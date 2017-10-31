cmake_minimum_required (VERSION 3.2)
project (LintCode)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_BUILD_TYPE "Debug")  
set (CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -g2 -ggdb")  
set (CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3")

## 线性表
### 数组
add_executable (remove_duplicates_from_sorted_array remove_duplicates_from_sorted_array.cc)
add_executable (long_consecutove_sequence long_consecutove_sequence.cc)
add_executable (two_sum two_sum.cc)
add_executable (remove_element remove_element.cc)
add_executable (3sum_closest 3sum_closest.cc)
add_executable (next_permutation next_permutation.cc)
add_executable (trapping_rain_water trapping_rain_water.cc)
add_executable (rotate_image rotate_image.cc)
add_executable (plus_one plus_one.cc)
add_executable (climbing_stairs climbing_stairs.cc)
add_executable (set_matrox_zeros set_matrox_zeros.cc)
add_executable (gas_station gas_station.cc)
add_executable (candy candy.cc)
add_executable (single_number single_number.cc)
add_executable (single_number_1 single_number_1.cc)

### 单链表
add_executable (add_two_numbers add_two_numbers.cc)
add_executable (binary_tree_inorder_traversal binary_tree_inorder_traversal.cc)

## 字符串

## 栈和队列

## 树

### 二叉树的遍历
add_executable (binary_tree_preorder_traversal binary_tree_preorder_traversal.cc)
add_executable (binary_tree_inorder_traversal binary_tree_inorder_traversal.cc)

### 二叉树的构建

### 二叉查找树

### 二叉树的递归

## 排序
add_executable (merge_sorted_array merge_sorted_array.cc)
add_executable (merge_two_sorted_lists merge_two_sorted_lists.cc)
add_executable (merge_k_sorted_lists merge_k_sorted_lists.cc)

## 查找
add_executable (search_for_a_range search_for_a_range.cc)
add_executable (search_insert_position search_insert_position.cc)
add_executable (search_a_2d_matrix search_a_2d_matrix.cc)

## 暴力枚举

## 广度优先搜索

## 深度优先搜索

## 分治法

## 贪心法

## 动态规划

## 图

## 细节实现

