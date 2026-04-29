/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.

*/
int findMax(int* piles, int pilesSize) {
    int max = piles[0];
    for(int i = 1; i < pilesSize; i++) {
        if(piles[i] > max)
            max = piles[i];
    }
    return max;
}

int canEat(int* piles, int pilesSize, int h, int k) {
    int hours = 0;

    for(int i = 0; i < pilesSize; i++) {
        hours += (piles[i] + k - 1) / k; // ceil
    }

    return hours <= h;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int low = 1;
    int high = findMax(piles, pilesSize);
    int ans = high;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(canEat(piles, pilesSize, h, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}