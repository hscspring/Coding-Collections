class Solution:
    def findMedianSortedArrays(self, nums1: list, nums2: list) -> float:
        arr = []
        i, j = 0, 0
        n = len(nums1) + len(nums2)

        index = int(n/2)

        if len(nums1) == 0:
            arr = nums2
        elif len(nums2) == 0:
            arr = nums1
        else:
            while (i < len(nums1) and j < len(nums2)):
                if nums1[i] <= nums2[j]:
                    item = nums1[i]
                    i = i + 1
                else:
                    item = nums2[j]
                    j = j + 1
                arr.append(item)

                if len(arr) == index + 1:
                    break
            if len(arr) < index + 1:
                if i == len(nums1):
                    arr.extend(nums2[j:])
                elif j == len(nums2):
                    arr.extend(nums1[i:])

        if n == 0:
            res = 0
        elif n % 2 == 0:
            res = (arr[index] + arr[index-1])/2
        else:
            res = arr[index]/1
        return res


if __name__ == '__main__':
    solution = Solution()
    nums1 = [1, 3]
    nums2 = [2]
    assert solution.findMedianSortedArrays(nums1, nums2) == 2.0

    nums1 = [1, 2]
    nums2 = [3, 4]
    assert solution.findMedianSortedArrays(nums1, nums2) == 2.5

    nums1 = [1]
    nums2 = [2, 4]
    assert solution.findMedianSortedArrays(nums1, nums2) == 2.0

    nums1 = [1, 3, 5]
    nums2 = [2, 4, 6]
    assert solution.findMedianSortedArrays(nums1, nums2) == 3.5

    nums1 = [1, 7]
    nums2 = [2, 4, 6]
    assert solution.findMedianSortedArrays(nums1, nums2) == 4.0

    nums1 = [1, 3, 5, 7]
    nums2 = [2, 10]
    assert solution.findMedianSortedArrays(nums1, nums2) == 4.0

    nums1 = [1]
    nums2 = []
    assert solution.findMedianSortedArrays(nums1, nums2) == 1.0

    nums1 = []
    nums2 = [1]
    assert solution.findMedianSortedArrays(nums1, nums2) == 1.0

    nums1 = []
    nums2 = []
    assert solution.findMedianSortedArrays(nums1, nums2) == 0.0

    nums1 = [1,2]
    nums2 = [1,2,3]
    assert solution.findMedianSortedArrays(nums1, nums2) == 2.0

    nums1 = [2]
    nums2 = [1, 3]
    assert solution.findMedianSortedArrays(nums1, nums2) == 2.0

    nums1 = []
    nums2 = [1, 3]
    assert solution.findMedianSortedArrays(nums1, nums2) == 2.0

