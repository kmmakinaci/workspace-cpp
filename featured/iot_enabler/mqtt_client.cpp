#include <iostream>
#include <mqtt/async_client.h>
#include <memory>
#include <thread>
#include <chrono>

const std::string SERVER_ADDRESS {"tcp://localhost:1883"};
const std::string CLIENT_ID {"mqtt_client"};
const std::string SECURE_SERVER_ADDRESS {"ssl://localhost:8883"};
const std::string SECURE_CLIENT_ID {"mqtt_client_secure"};
const std::string TOPIC{"test/topic"};

class callback : public virtual mqtt::callback {
public:
    // Callback to handle incoming messages
    void message_arrived(mqtt::const_message_ptr msg) override {
        std::cout << "Received message: " << msg->get_payload_str() << " on topic " << msg->get_topic() << std::endl;
    }
};

class MqttClient {
public:
    virtual ~MqttClient() = default;
    virtual void connect() = 0;
    virtual void subscribe(const std::string& topic, int qos) = 0;
    virtual void publish(const std::string& topic, const std::string& payload, int qos) = 0;
    virtual void unsubscribe(const std::string& topic) = 0;
    virtual void disconnect() = 0;
};

class DefaultMqttClient : public MqttClient {
public:
    DefaultMqttClient(const std::string& server_address, const std::string& client_id)
        : client(server_address, client_id) {
        client.set_callback(cb);
    }

    void connect() override {
        client.connect()->wait();
    }

    void subscribe(const std::string& topic, int qos) override {
        client.subscribe(topic, qos);
    }

    void publish(const std::string& topic, const std::string& payload, int qos) override {
        client.publish(topic, payload, qos);
    }

    void unsubscribe(const std::string& topic) override {
        client.unsubscribe(topic);
    }

    void disconnect() override {
        client.disconnect()->wait();
    }

private:
    mqtt::async_client client;
    callback cb;
};

class TlsMqttClient : public MqttClient {
public:
    TlsMqttClient(const std::string& server_address, const std::string& client_id)
        : client(server_address, client_id) {
        setConnectionOptions();
        client.set_callback(cb);
    }

    void connect() override {
        client.connect(conn_opts)->wait();
    }

    void subscribe(const std::string& topic, int qos) override {
        client.subscribe(topic, qos);
    }

    void publish(const std::string& topic, const std::string& payload, int qos) override {
        client.publish(topic, payload, qos);
    }

    void unsubscribe(const std::string& topic) override {
        client.unsubscribe(topic);
    }

    void disconnect() override {
        client.disconnect()->wait();
    }

private:
    mqtt::async_client client;
    mqtt::connect_options conn_opts;
    callback cb;

    void setConnectionOptions() {
        mqtt::ssl_options ssl_opts;
        ssl_opts.set_trust_store("ca.pem");
        conn_opts.set_ssl(ssl_opts);
    }
};

class MqttClientFactory {
public:
    static std::unique_ptr<MqttClient> createClient(bool use_tls) {
        if (use_tls) {
            return std::make_unique<TlsMqttClient>(SECURE_SERVER_ADDRESS, SECURE_CLIENT_ID);
        } else {
            return std::make_unique<DefaultMqttClient>(SERVER_ADDRESS, CLIENT_ID);
        }
    }
};

int main() {
    try {
        bool use_tls = true; // Change this flag to switch between TLS and non-TLS
        auto client = MqttClientFactory::createClient(use_tls);

        client->connect();
        client->subscribe(TOPIC, 1);
        client->publish(TOPIC, "Hello MQTT", 1);
        std::this_thread::sleep_for(std::chrono::seconds(5));
        client->unsubscribe(TOPIC);
        client->disconnect();
    } catch (const mqtt::exception& exc) {
        std::cerr << "MQTT exception: " << exc.what() << std::endl;
        return 1;
    }

    return 0;
}