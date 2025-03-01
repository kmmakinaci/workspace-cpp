#include <coap3/coap.h>
#include <iostream>

#define COAP_SERVER "coap://coap.me"
#define COAP_RESOURCE "test"

int main() {
    coap_startup();
    coap_session_t *session;
    coap_context_t *ctx = coap_new_context(nullptr);
    coap_address_t dst;
    
    coap_address_init(&dst);
    dst.addr.sin.sin_family = AF_INET;
    dst.addr.sin.sin_port = htons(5683); // Default CoAP port

    session = coap_new_client_session(ctx, nullptr, &dst, COAP_PROTO_UDP);
    
    if (!session) {
        std::cerr << "Failed to create CoAP session!" << std::endl;
        return -1;
    }

    coap_pdu_t *pdu = coap_pdu_init(COAP_MESSAGE_CON, COAP_REQUEST_GET, coap_new_message_id(session), 64);
    coap_add_option(pdu, COAP_OPTION_URI_PATH, strlen(COAP_RESOURCE), (const uint8_t *)COAP_RESOURCE);
    
    coap_send(session, pdu);
    coap_run_once(ctx, 0);
    
    coap_free_context(ctx);
    coap_cleanup();

    return 0;
}
