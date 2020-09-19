// partition of array into k contiguous subarrays such that bitwise AND of sum of each subarray is maximum
// https://stackoverflow.com/questions/55621259/partition-of-array-into-k-contiguous-subarrays-such-that-bitwise-and-of-sum-of-e


function f(array, numSegments) {
  const n = array.length;
  const maxBit = (1 << 30); // note: can improve if desired

  if (numSegments > n) {
    throw 'Too many segments.';
  }

  /* prefixSums[i] will be the sum of array[0..(i-1)], so that
   * the sum of array[i..j] will be prefixSums[j+1]-prefixSums[i].
   * This is a small optimization and code simplification, but the
   * same asymptotic complexity is possible without it.
   */
  const prefixSums = [];
  prefixSums[0] = 0;
  for (let i = 1; i <= n; ++i) {
    prefixSums.push(prefixSums[i-1] + array[i-1]);
  }

  /* bestKnownBitmask will be the result -- the best bitmask that we
   * could achieve. It will grow by one bit at a time; for example,
   * if the correct answer is binary 1011, then bestKnownBitmask will
   * start out as 0000, then later become 1000, then later 1010, and
   * finally 1011.
   */
  let bestKnownBitmask = 0;

  /* startIndices[seg] will be a list of start-indices where
   * it's possible to divide the range from such a start-index to
   * the end of the array into 'seg' segments whose sums all satisfy
   * a given bitmask condition.
   *
   * In particular, startIndices[0] will always be [n], because the
   * only way to get zero segments is to have zero elements left; and
   * startIndices[numSegments][0] will always be 0, because we only
   * keep a bitmask condition if we successfully found a way to
   * partition the entire array (0..(n-1)) into 'numSegments' segments
   * whose sums all satisfied it.
   */
  let startIndices = [];
  startIndices.push([n]);
  for (let seg = 1; seg <= numSegments; ++seg) {
    startIndices.push([]);
    for (let i = numSegments - seg; i <= n - seg; ++i) {
      startIndices[seg].push(i);
    }
  }

  for (let currBit = maxBit; currBit > 0; currBit >>= 1) {
    const bitmaskToTry = (bestKnownBitmask | currBit);

    const tmpStartIndices = startIndices.map(row => []); // empty copy
    tmpStartIndices[0].push(n);

    for (let seg = 1; seg <= numSegments; ++seg) {
      for (const startIndex of startIndices[seg]) {
        for (const nextIndex of tmpStartIndices[seg-1]) {
          if (nextIndex <= startIndex) {
            continue;
          }
          const segmentSum = prefixSums[nextIndex] - prefixSums[startIndex];
          if ((segmentSum & bitmaskToTry) === bitmaskToTry) {
            tmpStartIndices[seg].push(startIndex);
            break;
          }
        }
      }
    }

    if (tmpStartIndices[numSegments].length > 0
        && tmpStartIndices[numSegments][0] === 0) {
      // success!
      bestKnownBitmask = bitmaskToTry;
      startIndices = tmpStartIndices;
    }
  }

  return bestKnownBitmask;
}

function runFunctionAndLogResult(array, numSegments) {
  let startTime = performance.now();
  let result = f(array, numSegments);
  let endTime = performance.now();
  console.log(
    'array = [' + array.join(', ') + ']\n' +
    'k = ' + numSegments + '\n' +
    'result = ' + result + '\n' +
    'time = ' + (endTime - startTime) + ' ms'
  );
}

runFunctionAndLogResult(
  [ 25, 40, 45, 69, 26, 13, 49, 49, 84, 67, 30, 22, 43, 82, 2, 95, 96, 63, 78, 26, 95, 57, 80, 8, 85, 23, 64, 85, 12, 66, 74, 69, 9, 35, 69, 89, 34, 2, 60, 91, 79, 99, 64, 57, 52, 56, 89, 20, 8, 85 ],
  12
);