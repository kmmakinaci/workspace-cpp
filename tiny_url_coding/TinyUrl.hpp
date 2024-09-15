#include <unordered_map>
#include <string>
#include <random>

class TinyUrl {
private:
    long long generateRandomNumber() noexcept {
        std::random_device rd;  // Seed the generator
        std::mt19937 gen(rd());  // Mersenne Twister random number generator
        std::uniform_int_distribution<long long> distrib(1, 999999999999);  // Generate a random number in this range
        return distrib(gen);
    }
    
    //A map to store the mapping between long URL format and shorts
    std::unordered_map<std::string, std::string> urlMap;
    long long id = generateRandomNumber();
    const std::string baseUrl = "http://tinyurl.com/";
    const std::string charset = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";  // Base-62 characters
    
    //Base-62 encoded string
    std::string idToShortUrl(long long id){
        std::string shortUrl;
        while(id){
            shortUrl.push_back(charset[id%62]);
            id /= 62;
        }
        while(shortUrl.length()<6){
            shortUrl.push_back('a');
        }
        return shortUrl;
    }


public:
    //Encodes a URL to shortened URL
    std::string encode(std::string longUrl) {
        std::string shortUrl = baseUrl + idToShortUrl(id);
        urlMap[shortUrl] = longUrl;
        return shortUrl;
    };

    std::string decode(std::string shortUrl) {
        return urlMap[shortUrl];
    };
};