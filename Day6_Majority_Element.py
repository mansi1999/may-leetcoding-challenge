# -*- coding: utf-8 -*-
"""
Created on Wed May  6 14:40:44 2020

@author: MANSI

Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3

Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2


"""
from collections import Counter
def majorityElement(nums):
        k = len(nums)//2
        count = Counter(nums)
        for i in nums:
            if count[i]>k:
                return i
            