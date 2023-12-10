#ifndef DYNARR_HPP
#define	DYNARR_HPP

#include <cstddef>
#include <stdexcept>

class DynArr {
public:
	DynArr() = default;
	explicit DynArr(const DynArr& x);    //done
	DynArr(const std::ptrdiff_t s);     //done
	~DynArr();                          //done
	std::ptrdiff_t Size() const;        //done
	void Resize(const std::ptrdiff_t s);
	float& operator[](const std::ptrdiff_t i);        //done
	const float& operator[](const std::ptrdiff_t i) const;    //done
	std::ptrdiff_t capacity() const noexcept {
		return capacity_;
	}
private:
	std::ptrdiff_t size_ = 0;
	std::ptrdiff_t capacity_ = 0;
	float* data_ = nullptr;
};

#endif