# -*- coding: utf-8 -*-
"""
Created on Wed May  6 14:44:38 2020

@author: MANSI
"""


def majorityElement(nums):
        k = len(nums)//2
        nums.sort()
        return nums[k]
            