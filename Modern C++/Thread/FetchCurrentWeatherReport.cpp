#include <iostream>
#include <thread>
#include <vector>
#include <curl/curl.h>

// Callback function to handle data received from curl
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
    size_t totalSize = size * nmemb;
    userp->append((char*)contents, totalSize);
    return totalSize;
}

// Function to fetch weather data for a given city
void fetchWeather(const std::string& city, const std::string& apiKey) {
    CURL* curl;
    CURLcode res;
    std::string readBuffer;

    // Initialize curl
    curl = curl_easy_init();
    if (curl) {
        std::string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey;
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the request
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "Weather data for " << city << ":\n" << readBuffer << "\n" << std::endl;
        }

        // Cleanup
        curl_easy_cleanup(curl);
    } else {
        std::cerr << "Failed to initialize CURL" << std::endl;
    }
}

int main() {
    // Replace this with your OpenWeatherMap API key
    const std::string apiKey = "<YOUR_API_KEY>";

    // List of cities
    std::vector<std::string> cities = {"New York", "London", "Tokyo", "Sydney", "Mumbai"};

    // Vector to hold threads
    std::vector<std::thread> threads;

    // Launch threads to fetch weather data for each city
    for (const auto& city : cities) {
        threads.emplace_back(fetchWeather, city, apiKey);
    }

    // Join all threads
    for (auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    std::cout << "All weather data fetched!" << std::endl;
    return 0;
}
