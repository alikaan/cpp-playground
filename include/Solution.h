#pragma once

#include <vector>
#include <numeric>  // For std::gcd

class Solution {
    public:
        static void moveZeroesToEnd(std::vector<int>& nums)
        { 
            int insertPos = 0;

            // Move all non-zero elements forward
            for (int num : nums) {
                if (num != 0) {
                    nums[insertPos++] = num;
                }
            }

            // Fill the rest with zeroes
            while (insertPos < nums.size()) {
                nums[insertPos++] = 0;
            }
        }

        static std::string reverseWords(std::string s)
        {
            std::istringstream iss(s);
            std::string word;
            std::vector<std::string> words;
            while (iss >> word) {
                words.push_back(word);
            }
            std::reverse(words.begin(), words.end());
            // Join them back with single space
            std::ostringstream oss;
            for (size_t i = 0; i < words.size(); ++i) {
                if (i > 0) oss << ' ';
                oss << words[i];
            }
            return oss.str();
        }

        static std::string gcdOfStrings(std::string str1, std::string str2) {
            if (str1 + str2 != str2 + str1) {
                return "";
            }

            int gcdLength = std::gcd(str1.size(), str2.size());
            return str1.substr(0, gcdLength);
        }

        static std::vector<int> countBits(int n) {
            std::vector<int> ans(n + 1, 0);

            for (int i = 1; i <= n; ++i) {
                ans[i] = ans[i >> 1] + (i & 1);
            }

            return ans;   
        }

        static void drawReversedPyramid(int count) {
            int spaceCount = 0;
            for(int i = 0; i < count; i++) {
                for(int j = 0; j < spaceCount; ++j) {
                    std::cout << " ";
                }
                for(int k = 0; k < count - i; ++k) {
                    std::cout << "* ";
                }
                std::cout << std::endl;
                spaceCount++;
            }
        }
};