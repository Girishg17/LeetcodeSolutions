class ProductOfNumbers {
public:
    vector<int> prod;
    int lastZeroIndex = -1;  // Keeps track of the last zero index to avoid incorrect division.

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            prod.push_back(1);  // Reset the product sequence when zero is added.
            lastZeroIndex = prod.size() - 1;
        } else {
            if (prod.empty()) {
                prod.push_back(num);
            } else {
                prod.push_back(prod.back() * num);
            }
        }
    }

    int getProduct(int k) {
        int size = prod.size();
        int startIndex = size - k;
        
        if (startIndex <= lastZeroIndex) {
            return 0;  // If there is a zero in the last `k` elements, the product is 0.
        }
        
        if (startIndex == 0) {
            return prod.back();
        }
        
        return prod.back() / prod[startIndex - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
