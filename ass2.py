def union(cricket,badminton):
    both=[]
    for i in cricket:
        if i in badminton:
            both.append(i)
    print('students who play both cricket and badminton:',sum(both))
def union1(cricket,badminton):
    cr=[]
    bad=[]
    for i in cricket:
        if i not in badminton:
            cr.append(i)
    for j in badminton:
        if j not in cricket:
            bad.append(j)
    print('students who play cricket:',sum(cr),' students who play badminton:',sum(bad))

def intersection(cricket,badminton,football):
    n_c_b=[]
    for i in football:
        if i not in cricket and i not in badminton:
            n_c_b.append(i)
    print('Students who  play neither cricket nor badminton:',sum(n_c_b))

def intersection2(cricket,badminton,football):
    c_b_n_b=[]
    f_b_n_b=[]
    for i in cricket:
        if i  in  cricket and i not in badminton:
            c_b_n_b.append(i)
    for j in football :
        if i in football and i not in badminton:
            f_b_n_b.append(j)
    print('Students who  play cricket and football but not badminton.:',sum(c_b_n_b+f_b_n_b))

cricket=[1,2,3,8,9,5]
badminton=[1,3,8,6,7]
football=[4,2]
union(cricket,badminton)
union1(cricket,badminton)
intersection(cricket,badminton,football)
intersection2(cricket,badminton,football)



