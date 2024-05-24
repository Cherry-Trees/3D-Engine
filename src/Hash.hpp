namespace Hash
{
    using hash_t = long long;
    using size_t = unsigned long long;
    using data_t = unsigned char *;

    constexpr hash_t generate(void *data, size_t size) {
        hash_t value = 0x00305f7;
        data_t pdata = (data_t)data;
        for (size_t i = 0; i < size; i++) {
            value << 4;
            value += pdata[i];
        }
        return value;
    }

    constexpr hash_t generate(const void *data, size_t size) {
        hash_t value = 0x00305f7;
        data_t pdata = (data_t)data;
        for (size_t i = 0; i < size; i++) {
            value << 4;
            value += pdata[i];
        }
        return value;
    }
}