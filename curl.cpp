#include <curl/curl.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// SFTP credentials
const string SFTP_HOSTNAME = "sftp.example.com";
const string SFTP_USERNAME = "username";
const string SFTP_PASSWORD = "password";
const string SFTP_REMOTE_PATH = "/remote/path/file.txt";
const string SFTP_LOCAL_PATH = "/local/path/file.txt";

// Callback function for writing downloaded data to a file
static size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream) {
    size_t written = fwrite(ptr, size, nmemb, (FILE *)stream);
    return written;
}

/*
This code uses the libcurl library to perform the SFTP transfer. The SFTP 
credentials are defined as constants at the beginning of the file, and the 
write_data() function is used as a callback to write the downloaded data to a
file. The main function sets the URL and options, performs the transfer, and 
cleans up after itself.
*/
int main() {
    CURL *curl;
    CURLcode res;
    FILE *fp;
    string sftp_url = "sftp://" + SFTP_USERNAME + ":" + SFTP_PASSWORD + "@" +
            SFTP_HOSTNAME + SFTP_REMOTE_PATH;

    // Initialize curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        // Set URL and options
        curl_easy_setopt(curl, CURLOPT_URL, sftp_url.c_str());
        curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_SFTP);
        curl_easy_setopt(curl, CURLOPT_USERNAME, SFTP_USERNAME.c_str());
        curl_easy_setopt(curl, CURLOPT_PASSWORD, SFTP_PASSWORD.c_str());

        // Set callback function to write downloaded data to file
        fp = fopen(SFTP_LOCAL_PATH.c_str(), "wb");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

        // Perform the SFTP transfer
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
        fclose(fp);
    } else {
        cerr << "curl_easy_init() failed" << endl;
        return 1;
    }

    curl_global_cleanup();
    return 0;
}




#include <curl/curl.h>
#include <stdio.h>

int main(int argc, char** argv)
{
    // Initialize libcurl
    curl_global_init(CURL_GLOBAL_ALL);

    // Create a CURL handle
    CURL* curl = curl_easy_init();
    if (!curl)
    {
        printf("Error: could not initialize curl\n");
        return 1;
    }

    // Set SFTP parameters
    curl_easy_setopt(curl, CURLOPT_PROTOCOLS, CURLPROTO_SFTP); // use SFTP protocol
    curl_easy_setopt(curl, CURLOPT_SSH_AUTH_TYPES, CURLSSH_AUTH_PASSWORD); // authenticate with password
    curl_easy_setopt(curl, CURLOPT_USERNAME, "username"); // set username
    curl_easy_setopt(curl, CURLOPT_PASSWORD, "password"); // set password
    curl_easy_setopt(curl, CURLOPT_SSH_KNOWNHOSTS, "/path/to/known_hosts"); // set path to known hosts file

    // Set file to upload
    FILE* fp = fopen("/path/to/local/file.txt", "rb");
    if (!fp)
    {
        printf("Error: could not open file\n");
        return 1;
    }
    curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(curl, CURLOPT_READDATA, fp);
    curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE, (curl_off_t)filesize);

    // Set destination path
    curl_easy_setopt(curl, CURLOPT_URL, "sftp://example.com/path/to/remote/file.txt");

    // Perform the upload
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
    {
        printf("Error: curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        return 1;
    }

    // Cleanup
    curl_easy_cleanup(curl);
    curl_global_cleanup();

    return 0;
}
