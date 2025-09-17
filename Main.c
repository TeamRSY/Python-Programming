// Bubble Sort
int main() {
    int n, i, j, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n-1; i++) {          // Number of passes
        for(j = 0; j < n-i-1; j++) {    // Compare adjacent elements
            if(arr[j] > arr[j+1]) {     // Swap if in wrong order
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Insertion Sort
int main() {
    int n, i, j, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 1; i < n; i++) {       // Start from 2nd element
        key = arr[i];              // Current element to be inserted
        j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;          // Place the key at the right position
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Selection Sort
int main() {
    int n, i, j, minIndex, temp;

    // Step 1: Take array size from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Selection Sort logic
    for(i = 0; i < n-1; i++) {
        minIndex = i; // assume the first element is the smallest

        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j; // update index of smallest element
            }
        }

        // Swap the found minimum element with the first element
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    // Step 4: Print sorted array
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

// Heap Sort

void heapify(int arr[], int n, int i) {
    int largest = i;        // Assume root is largest
    int left = 2 * i + 1;   // left child
    int right = 2 * i + 2;  // right child

    // If left child is larger than root
    if(left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if(right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if(largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;

    // Build a max heap
    for(i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract elements
    for(i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n, i;

    // Step 1: Input size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Step 2: Input elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Call heap sort
    heapSort(arr, n);

    // Step 4: Print sorted array
    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}


// Liner Search
int main() {
    int n, i, key, found = 0;

    // Step 1: Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Step 2: Input array elements
    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Input the element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Step 4: Linear Search logic
    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            printf("Element %d found at position %d\n", key, i+1);
            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}

// Binary Search
int main() {
    int n, i, key, low, high, mid, found = 0;

    // Step 1: Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Step 2: Input array elements (must be sorted!)
    printf("Enter %d elements in sorted order:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Step 3: Input the element to search
    printf("Enter element to search: ");
    scanf("%d", &key);

    // Step 4: Binary Search logic
    low = 0;
    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            printf("Element %d found at position %d\n", key, mid+1);
            found = 1;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1; // search in right half
        }
        else {
            high = mid - 1; // search in left half
        }
    }

    if(found == 0) {
        printf("Element %d not found in the array.\n", key);
    }

    return 0;
}
