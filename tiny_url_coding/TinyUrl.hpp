#include <unordered_map>
#include <string>

class TinyUrl {
private:
    //A map to store the mapping between long URL format and shorts
    std::unordered_map<std::string, std::string> urlMap;
    int counter = 0;
    const std::string baseUrl = "http://tinyurl.com/";

public:
    //Encodes a URL to shortened URL
    std::string encode(std::string longUrl) {
        std::string shortUrl = baseUrl + std::to_string(counter);
        urlMap[shortUrl] = longUrl;
        counter++;
        return shortUrl;
    };

    std::string decode(std::string shortUrl) {
        return urlMap[shortUrl];
    };
};