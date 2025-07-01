#include "FibonacciSequenceIterator.h"


FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence* aSequence, uint64_t aStart) 
noexcept: 
    fSequence(aSequence), 
    fIndex(aStart) 
{}

const uint64_t& FibonacciSequenceIterator::operator*() const noexcept 
{
    return **fSequence;
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++() noexcept 
{
    ++(*fSequence);
    ++fIndex;
    return *this; 
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int) noexcept 
{
    FibonacciSequenceIterator old = *this;
    ++(*this);
    return old;
}

bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const noexcept 
{
    return fIndex == aOther.fIndex;
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const noexcept
{
    FibonacciSequenceIterator copy = *this;
    if (copy.fSequence != nullptr)
    {
        copy.fSequence->begin();   
    }

    copy.fIndex = 0;
    return copy;
}


FibonacciSequenceIterator FibonacciSequenceIterator::end() const noexcept
{
    FibonacciSequenceIterator copy = *this;

    if (fSequence != nullptr)
    {
        copy.fIndex = 93;
    }

    return copy;
}
