#include <iostream>
#include <mqtt/async_client.h>

const std::string SERVER_ADDRESS {"tcp://localhost:1883"};
const std::string CLIENT_ID {"mqtt_client"};
const std::string TOPIC{"test/topic"};

class callback : public virtual mqtt::callback {
public:
    // Callback to handle incoming messages
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Received message: " << msg->get_payload_str() << "on topic " << msg->get_topic() << std::endl;
    }
};

int main() {
    mqtt::async_client client(SERVER_ADDRESS, CLIENT_ID);
    callback cb;
    client.set_callback(cb);

    try{
        client.connect()->wait();
        client.subscribe(TOPIC, 1);
        client.publish(TOPIC, "Hello MQTT",1);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        client.unsubscribe(TOPIC);
        client.disconnect()->wait();
    } catch(const mqtt::exception& exc){
        std::cerr << "MQTT exception: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}