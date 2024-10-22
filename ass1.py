def FDS():
    stud = [45, 55, 66, 12, 88, 99, 88, None, None]
    total_score = 0
    valid_scores = 0
    absents = 0
    freq_dict = {}
    for i in stud:
        if i is not None:
            total_score += i
            valid_scores += 1
        else:
            absents += 1
    avg = total_score / valid_scores if valid_scores > 0 else 0
    valid_marks = [i for i in stud if i is not None]
    highest_score = max(valid_marks)
    for mrk in valid_marks:
        if mrk in freq_dict:
            freq_dict[mrk] += 1
        else:
            freq_dict[mrk] = 1
    most_frequent_mark = max(freq_dict, key=freq_dict.get)
    print('The average score of the class is:', avg)
    print('The highest score of the class is:', highest_score)
    print(absents, 'students were absent for the test!')
    print('The highest frequency of marks is:', most_frequent_mark, 'with frequency:', freq_dict[most_frequent_mark])
FDS()
