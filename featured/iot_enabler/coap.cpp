#include <coap3/coap.h>
#include <iostream>
#include <stdexcept>
#include <string>

#define COAP_SERVER "coap://coap.me"
#define COAP_RESOURCE "test"

class CoapClient {
public:
    CoapClient() {
        coap_startup();
        coap_context_t *ctx = coap_new_context(nullptr);
        if (!ctx) {
            throw std::runtime_error("Failed to create CoAP context!");
        }

        coap_address_init(&dst);
        dst.addr.sin.sin_family = AF_INET;
        dst.addr.sin.sin_port = htons(5683); // Default CoAP port
        
        session = coap_new_client_session(ctx, nullptr, &dst, COAP_PROTO_UDP);
        if (!session) {
            coap_free_context(ctx);
            throw std::runtime_error("Failed to create CoAP session!");
        }
    }

    ~CoapClient() {
        if (session) {
            coap_session_release(session);
        }
        if (ctx) {
            coap_free_context(ctx);
            coap_cleanup();
        }
    }

    void sendGetRequest(const std::string& resource) {
        coap_pdu_t *pdu = coap_pdu_init(COAP_MESSAGE_CON, COAP_REQUEST_GET, coap_new_message_id(session), coap_session_max_pdu_size(session));
        if (!pdu) {
            throw std::runtime_error("Failed to create CoAP PDU!");
        }
        
        coap_add_option(pdu, COAP_OPTION_URI_PATH, resource.size(), (const uint8_t *)COAP_RESOURCE);

        coap_register_response_handler(ctx, handleGetResponse);
        
        if( coap_send(session, pdu) == COAP_INVALID_TID) {
            throw std::runtime_error("Failed to send CoAP request!");
        }
        
        coap_run_once(ctx, 0);
    }

private:
    coap_context_t* ctx = nullptr;
    coap_session_t* session = nullptr;
    coap_address_t dst;

    static void handleGetResponse(coap_context_t* ctx, coap_session_t* session, coap_pdu_t* sent, coap_pdu_t* received, coap_tid_t id) {
        if (received) {
            std::cout << "Received response: ";
            coap_show_pdu(received);
        }
    }
};

int main() {
    try{
        CoapClient client;
        client.sendGetRequest(COAP_RESOURCE);
    } catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
        return -1;
    }

    return 0;
}
