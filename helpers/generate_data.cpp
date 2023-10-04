#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>

const long long num_rows = 1000000;  // 1 million rows

std::string random_string(int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string random_str(length, '\0');
    for (int i = 0; i < length; ++i) {
        random_str[i] = alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return random_str;
}

int main() {
    std::ofstream outfile("large_data.json");
    if (!outfile) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(0)));

    outfile << "[";

    long long i = 0;

    for (i = 0; i < num_rows; ++i) {
        if (i > 0) outfile << ",";
        outfile << "{\"id\":" << rand() << ",";
        outfile << "\"email\":\"" << random_string(10) << "@example.com\",";
        outfile << "\"sale_date\":\"2023-01-01\",";
        outfile << "\"amount_1\":" << (rand() % 1000) + 10 << ",";
        outfile << "\"amount_2\":" << (rand() % 1000) + 10 << ",";
        outfile << "\"amount_3\":" << (rand() % 1000) + 10 << ",";
        outfile << "\"amount_4\":" << (rand() % 1000) + 10 << ",";
        outfile << "\"amount_5\":" << (rand() % 1000) + 10 << "}";

        // Print progress
        if (i % 1000 == 0)
            std::cout << "Generated " << i << " rows..." << std::endl;
    }

    outfile << "]";

    outfile.close();

    std::cout << i << " rows generated and saved to 'large_data.json'." << std::endl;

    return 0;
}
