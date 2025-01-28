#include <iostream>
#include <vector>

void convertPrefixSum(std::vector<int> &nums) {
  for (int i = 1; i < nums.size(); ++i) {
    nums[i] += nums[i - 1];
  }
}

void find2DPrefixSum(std::vector<std::vector<int>> &A) {
  std::vector<std::vector<int>> prefixSum(A.size(), std::vector<int>(A[0].size(), 0));
  for (int row = 0; row < A.size(); ++row) {
    prefixSum[row] = A[row];
    convertPrefixSum(prefixSum[row]);
  }

  for (int col = 0; col < A[0].size(); ++col) {
    A[0][col] = prefixSum[0][col];
    for (int row = 1; row < A.size(); ++row) {
      A[row][col] = A[row - 1][col] + prefixSum[row][col];
    }
  }
}

int main() {
  std::vector<std::vector<int>> nums = {
      {2, 4, -3, 10}, {1, -5, 7, 8}, {3, 11, 5, 9}, {-4, 1, 6, -13}};

  find2DPrefixSum(nums);
  for (const auto &vec : nums) {
    std::cout << "[";
    for (const int &num : vec) {
      std::cout << num << " ";
    }
    std::cout << "]\n";
  }
  return 0;
}
