#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdexcept>

namespace udp_client_server
{
    class udp_client_server_runtime_error : public std::runtime_error
    {
    public:
        udp_client_server_runtime_error(const char *w) : std::runtime_error();
    };

    class udp_client
    {
    public:
        udp_client(const std::string &addr, int port);
        ~udp_client();

        int get_socket() const;
        int get_port() const;
        std::string get_addr() const;

        int send(const char *msg, size_t size);

    private:
        int m_socket;
        int m_port;
        std::string m_addr;
        struct addrinfo *m_addrinfo;
    };

    class udp_server
    {
        udp_server(const std::string &adr, int port);
        
    };
}
