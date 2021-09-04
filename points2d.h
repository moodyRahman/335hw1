// --> YOUR NAME here
// Few comments describing the class Points2

#ifndef CSCI335_HOMEWORK1_POINTS2D_H_
#define CSCI335_HOMEWORK1_POINTS2D_H_

#include <array>
#include <iostream>
#include <cstddef>
#include <string>
#include <sstream>

namespace teaching_project {

// Place comments that provide a brief explanation of the class,
// and its sample usage.
template<typename Object>
class Points2D {
 public:
  // Default "big five" -- you have to alter them for your assignment.
  // That means that you will remove the "= default" statement.
  //  and you will provide an implementation.

  // Zero-parameter constructor. 
  // Set size to 0.
  Points2D<Object>()
  {
    this->size_ = 0;
  };

  Points2D<Object>(int s)
  {
    this->size_ = s;
    this->sequence_ = new std::array<Object, 2>[s];
  };

  // Copy-constructor.
  Points2D(const Points2D &rhs)
  {
    std::cout << "deep copy-ing" << std::endl;
    this->sequence_ = new std::array<Object, 2> [rhs.size_];
    this->size_ = rhs.size_;
    for (size_t x = 0; x < rhs.size_; x++)
    {
      this->sequence_[x][0] = rhs[x][0];
      this->sequence_[x][1] = rhs[x][1];
    }

  };

  // Copy-assignment. If you have already written
  // the copy-constructor and the move-constructor
  // you can just use:
  // {
  // Points2D copy = rhs; 
  // std::swap(*this, copy);
  // return *this;
  // }
  Points2D& operator=(const Points2D &rhs)
  {
    Points2D copy = rhs;
    std::swap(*this, copy);
    return *this;
  };

  // Move-constructor. 
  Points2D(Points2D &&rhs)
  : sequence_ {rhs.sequence_}
  , size_ {rhs.size_}
  {
    rhs.size_ = 0;
    rhs.sequence_ = nullptr;

  };

  // Move-assignment.
  // Just use std::swap() for all variables.
  Points2D& operator=(Points2D &&rhs)
  {
    if (this != &rhs)
    {
      std::swap(this->sequence_, rhs.sequence_);
      std::swap(this->size_, rhs.size_);
    }
    return *this;
  };

  ~Points2D()
  {
    if (this->size_ > 0)
    {
      delete this->sequence_;
    }

  };

  // End of big-five.

  // One parameter constructor.
  Points2D(const std::array<Object, 2>& item) {
    this->size_ = 1;
    this->sequence_ = new std::array<Object, 2>[1];
    this->sequence_[0][0] = item[0];
    this->sequence_[0][1] = item[1];
  }

  // Read a chain from standard input.
  void ReadPoints2D() {
    // Part of code included (without error checking).
    std::string input_line;
    std::getline(std::cin, input_line); 
    std::stringstream input_stream(input_line);
    if (input_line.empty()) return;
    // Read size of sequence (an integer).
    int size_of_sequence;
    input_stream >> size_of_sequence;
    this->size_ = size_of_sequence;
    this->sequence_ = new std::array<Object, 2>[size_of_sequence];
    
    Object token;
    for (int i = 0 ;input_stream >> token; ++i) {
      this->sequence_[i][0] = token;
      input_stream >> token;
      this->sequence_[i][1] = token;
    }

  }

  size_t size() const {
    return this->size_;
  }

  // @location: an index to a location in the sequence.
  // @returns the point at @location.
  // const version.
  // abort() if out-of-range.
  std::array<Object, 2>& operator[](int location) const { 
    return this->sequence_[location];
  }


  //  @c1: A sequence.
  //  @c2: A second sequence.
  //  @return their sum. If the sequences are not of the same size, append the
  //    result with the remaining part of the larger sequence.
  friend Points2D operator+(const Points2D &c1, const Points2D &c2) {
    size_t biggest = c1.size_ > c2.size_ ? c1.size_ : c2.size_;
    size_t smallest = c1.size_ < c2.size_ ? c1.size_ : c2.size_;

    Points2D out (biggest);

    for (size_t x = 0; x < smallest; x++)
    {
      out[x][0] = c1[x][0] + c2[x][0];
      out[x][1] = c1[x][1] + c2[x][1];
    }
    

    return out;
  }

  // Overloading the << operator.
  friend std::ostream &operator<<(std::ostream &out, const Points2D &some_points2) {
    for(size_t x = 0; x < some_points2.size_; x++)
    {
      out << "(";
      out << some_points2[x][0];
      out << ", ";
      out << some_points2[x][1];
      out << ") ";
    }
    
    return out;
    }
 
  std::array<Object, 2> *sequence_;
  // Size of sequence.
  size_t size_;


};

}  // namespace teaching_project
#endif // CSCI_335_HOMEWORK1_POINTS2D_H_
