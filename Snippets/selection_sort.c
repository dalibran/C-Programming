 int maxIndex = arraySize - 1;

    while (maxIndex > 0) {
      for (int i = 0; i < maxIndex; i++) {
        if (array[i] > array[maxIndex]) {
          int temp;
          temp = array[i];
          *(array + i) = array[maxIndex];
          *(array + maxIndex) = temp;
        }
      }
      maxIndex--;
    }
