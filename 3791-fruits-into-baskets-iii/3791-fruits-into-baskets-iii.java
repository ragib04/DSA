class Solution {
    public int numOfUnplacedFruits(int[] fruits, int[] baskets) { // \U0001f34e\U0001f9fa
        int n = baskets.length; // \U0001f4cf
        // Calculate the square root 
        int blockSize = (int) Math.sqrt(n); // (int) -> an integer (4, not 4.0) // ➗
        // Why? To divide the baskets into groups of approximately the same size. // \U0001f914
        /*
        If n is completely divisible by blockSize: Then (n + blockSize - 1)/blockSize will give the same result as n/ blockSize. For example, if n = 16 and blockSize = 4, then 16 / 4 = 4, and (16 + 4 - 1) / 4 = 19 / 4 = 4. Adding blockSize - 1 does not affect the result.

    If n is not completely divisible by blockSize: Then adding blockSize - 1 ensures that we get enough blocks to fit all the bins. For example, if n = 17 and blockSize = 4, then 17 / 4 = 4, and (17 + 4 - 1) / 4 = 20 / 4 = 5. Without adding blockSize - 1, we would have received the wrong number of blocks (4 instead of 5).
         */ // \U0001f4da
        int blocksCount = (n + blockSize - 1) / blockSize; // \U0001f9ee
        // Why? To know how many groups of baskets we have in total. // \U0001f9d0

        // Creating an array to store the maximum values in each block // \U0001f3d7️
        int[] blockMax = new int[blocksCount]; // \U0001f195

        // Initialize the array with the maximum values for each block // \U0001f504
        for (int i = 0; i < n; i++) { // \U0001f501
            // Calculating the index of the block to which the current bucket belongs // \U0001f9ee
            int blockIndex = i / blockSize;  // \U0001f522
            // Why? To determine which group the current bucket is in. // \U0001f937

            // Update the maximum value in the block if the current bucket is larger // ⬆️
            blockMax[blockIndex] = Math.max(blockMax[blockIndex], baskets[i]);  // \U0001f51d
            // Why? To know the maximum bucket size in each group. // \U0001f4ca
        }

        // Counting the number of fruits that could not be placed // \U0001f9ee
        int unplacedCount = 0; // 0️⃣

        for (int fruit : fruits) { // \U0001f347
            boolean placed = false; // ❌

            // Looking for a suitable basket in the blocks // \U0001f50d
            for (int block = 0; block < blocksCount && !placed; block++) { // \U0001f504
                // If the maximum size of the basket in the block is less than the size of the fruit, move on to the next block // ⏭️
                if (blockMax[block] < fruit) {  // \U0001f4c9
                    continue;  // ⏩
                    // Why? In order not to waste time on blocks where there are definitely no suitable baskets. // ⏳
                }

                /* 
                Why is this necessary?

start is the index of the first element in the baskets array, which belongs to the third block (block with index 2).

Look:

    Block 0: Indexes of baskets elements from 0 to 2 (3 elements).
    Block 1: Indexes of baskets elements from 3 to 5 (3 elements).
    Block 2: Indexes of baskets elements from 6 to 8 (3 elements).
    Block 3: Indexes of baskets elements from 9 to 9 (1 element).

That is, when block = 2, we need to start sorting through the baskets with index 6 to check if there is a suitable basket for our fruit in this block.
                */ // \U0001f4d6
                // Found a block with a potential basket // \U0001f3af
                int start = block * blockSize;  // \U0001f3c1
                // Why? The initial index of the block. // \U0001f530

                int end = Math.min(start + blockSize, n);  // \U0001f3c1
                // Why? The end index of the block (or the end of the array, if the block is the last one). // \U0001f3c1

                // Looking for a suitable shopping cart inside the block // \U0001f50e
                for (int i = start; i < end; i++) { // \U0001f50d
// If the bucket is large enough // ✅
                    if (baskets[i] >= fruit) {  // ⚖️
                        baskets[i] = 0; // Marking the basket as used (zero) // 0️⃣
                        placed = true; // The fruit is placed // ✅
                        
                        // Updating the maximum value in the block // \U0001f504
                        blockMax[block] = 0;  // 0️⃣
                        for (int j = start; j < end; j++) { // \U0001f501
                            blockMax[block] = Math.max(blockMax[block], baskets[j]);  // \U0001f51d
                            // Why? We find the new maximum value in the block. // \U0001f50d
                        }
                        break; // Exiting the bucket loop in the block // \U0001f6aa
                    }
                }
            }
            // If the fruit could not be placed // ❌
            if (!placed) {  // \U0001f61e
                unplacedCount++;  // ➕
                // Increasing the counter of unplaced fruits. // \U0001f4c8
            }
        }

        return unplacedCount; // \U0001f3af
    }
}