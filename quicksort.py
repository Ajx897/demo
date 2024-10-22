def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)
def display_top_five(arr):
    arr_sorted = sorted(arr, reverse=True)
    top_five = arr_sorted[:5]
    print('Top five scores:', top_five)
student_scores = [78.5, 85.2, 90.3, 92.4, 70.9, 81.3, 88.5, 96.1, 75.8, 84.6]
print("Original Scores:", student_scores)
quick_sorted_scores = quick_sort(student_scores.copy())
print("\nScores after Quick Sort:", quick_sorted_scores)
display_top_five(quick_sorted_scores)
