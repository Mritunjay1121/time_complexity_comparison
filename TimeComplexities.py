## TIME COMPLEXITIES

import time
import random

print("STARTING FOR PYTHON ................")

## O(n)



start_o_of_n_time=time.time()
count=10000000
numbers_=[]
for v in range(1,count+1):
    numbers_.append(v)

end_o_of_n_time=time.time()
n_time=end_o_of_n_time-start_o_of_n_time
print(f"Time taken to count {count} is : ",n_time)




## O(n^2)

count =10000
numbers_on2 = [v for v in range(1,count+1)]
start_o_of_n_squared_time=time.time()
for i in range(len(numbers_on2)):
    for j in range(len(numbers_on2)):
        multiply=numbers_on2[i]*numbers_on2[j]
end_o_of_n_squared_time=time.time()
n2_time=end_o_of_n_squared_time-start_o_of_n_squared_time

print(f"Time taken for a n_squared operation on {count} is : ",n2_time)


## O(n.log(n))

count_nlogn =10000000
numbers_nlogn = [v for v in range(1,count_nlogn+1)]

start_o_of_n_logn_time=time.time()
numbers_nlogn.sort()

result = {}
current_count = 1
n = len(numbers_nlogn)

# Count occurrences of each element
for i in range(1, n):
    if numbers_nlogn[i] == numbers_nlogn[i - 1]:
        current_count += 1
    else:
        result[numbers_nlogn[i - 1]] = current_count
        current_count = 1
end_o_of_n_logn_time=time.time()

nlogn_time=end_o_of_n_logn_time-start_o_of_n_logn_time

print(f"Time taken for a n_logn operation on {count_nlogn} is : ",nlogn_time)


## O(log(n))


count_logn= 10000000
numbers_logn = sorted([random.randint(1, count_logn) for _ in range(count_logn)]) 

search_for = numbers_logn[random.randint(0, count_logn-1)]


start_time_logn = time.time()

low, high = 0, len(numbers_logn) - 1
found = False

while low <= high:
    mid = (low + high) // 2
    if numbers_logn[mid] == search_for:
        found = True
        break
    elif numbers_logn[mid] < search_for:
        low = mid + 1
    else:
        high = mid - 1

# End time
end_time_logn = time.time()

# Calculate and print the duration
logn_time = end_time_logn - start_time_logn

print(f"Time taken for a logn operation on {count_logn} is : ",logn_time)

print("ENDING FOR PYTHON ................")
