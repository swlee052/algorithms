
def kLengthApart(nums, k) -> bool:
    for i in range(len(nums)):
        print(range(len(nums)))
        if nums[i] == 1:
            for j in range(i+1, len(nums)):
                print(i, j)
                if nums[j] == 1 and j-i < k:
                    return False
                else:
                    continue      
    return True
print(kLengthApart([1,0,0,0,1,0,0,1], 2))


var kLengthApart = function(nums, k) {
    counter = k;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === 0) {
            counter--
        }
        if (nums[i] === 1) {
            if (counter > 0 && i > 0) {
                return false;
            }
            counter = k;
        }
    }
    return true;
};