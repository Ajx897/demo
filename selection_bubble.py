def selection_sort(arr):
    for i in range(len(arr)):
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr
def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr
def display_top_five(arr):
    arr_sorted = sorted(arr, reverse=True)
    top_five = arr_sorted[:5]
    print('Top five scores:', top_five)

student_scores = [88.5, 76.2, 93.4, 85.6, 92.3, 65.4, 79.8, 91.1, 83.5, 78.6]

print("Original Scores:", student_scores)
selection_sorted_scores = selection_sort(student_scores.copy())
print("\nScores after Selection Sort:", selection_sorted_scores)
display_top_five(selection_sorted_scores)
bubble_sorted_scores = bubble_sort(student_scores.copy())
print("\nScores after Bubble Sort:", bubble_sorted_scores)
display_top_five(bubble_sorted_scores)
