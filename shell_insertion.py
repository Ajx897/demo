def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr
def shell_sort(arr):
    n = len(arr)
    gap = n // 2
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        gap //= 2
    return arr
def display_top_five(arr):
    arr_sorted = sorted(arr, reverse=True)
    top_five = arr_sorted[:5]
    print('Top five scores:', top_five)

student_scores = [72.5, 81.4, 94.3, 78.5, 87.6, 65.8, 90.1, 88.9, 79.3, 83.4]

print("Original Scores:", student_scores)
insertion_sorted_scores = insertion_sort(student_scores.copy())
print("\nScores after Insertion Sort:", insertion_sorted_scores)
display_top_five(insertion_sorted_scores)
shell_sorted_scores = shell_sort(student_scores.copy())
print("\nScores after Shell Sort:", shell_sorted_scores)
display_top_five(shell_sorted_scores)
