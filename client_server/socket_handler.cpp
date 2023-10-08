constexpr const size_t adressSize = sizeof(sockaddr_in);
constexpr const uint16_t defaultPort = 80;  //The port you want to use

int serverSocket =socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
sockaddr_in serverAdress,clientAddress;

memset(&serverAddress, 0, addressSize);
serverAddress.sin_family = AF_INET;
serverAddress.sin_addr.s_addr = htonl(INADDR_ANY);
serverAddress.sin_port = htons(defaultPort);

bind(serverSocket, (sockaddr*)&serverAddress, addressSize);
listen(serverSocket, SOMAXCONN);

while(true){//infinite running app
    std::thread{//create new thread for every client
        handleConnection, //connectionHandler
        accept(serverSocket,(sockaddr*)&clientAddress, &addressSize)//Client socket
        //any other parameters for the handler here
    }.detach(); //detached thread to make resource management easier
}
return 0;