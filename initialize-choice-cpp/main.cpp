#include <iostream>

// Noncopyable, but moveable resource
struct Resource {
    Resource() = delete;
    Resource(const Resource&) = delete;
    Resource& operator=(const Resource&) = delete;

    Resource(Resource&&) = default;
    Resource& operator=(Resource&&) = default;

    static Resource from_string(const std::string& str)
    {
        return Resource { str.size() };
    }

    static Resource from_number(size_t number)
    {
        return Resource { number };
    }

    void print() const
    {
        std::cout << "data = " << data << std::endl;
    }

private:
    size_t data;
    Resource(size_t i)
        : data { i }
    {
    }
};

bool should_the_string_be_used()
{
    return true;
}

int main()
{
    std::string str_input = "hello";
    size_t number_input = 7;

    auto r = [&] {
        if (should_the_string_be_used()) {
            return Resource::from_string(str_input);
        } else {
            return Resource::from_number(number_input);
        }
    }();

    r.print();
}
