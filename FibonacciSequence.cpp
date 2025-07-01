#include "FibonacciSequence.h"

FibonacciSequence::FibonacciSequence() noexcept
	:fPrevious(0), fCurrent(1)
{}

const uint64_t& FibonacciSequence::operator*() const noexcept 
{
	return fCurrent;
}

FibonacciSequence& FibonacciSequence::operator++() noexcept
{
	uint64_t next = fPrevious + fCurrent;
	fPrevious = fCurrent;
	fCurrent = next;
	return *this;
}

FibonacciSequence FibonacciSequence::operator++(int) noexcept 
{
	FibonacciSequence old = *this;
	++(*this);
	return old;
}

bool FibonacciSequence::operator==(const FibonacciSequence& aOther) const noexcept 
{
	return fPrevious == aOther.fPrevious && fCurrent == aOther.fCurrent;
}

void FibonacciSequence::begin() noexcept 
{
	fPrevious = 0;
	fCurrent = 1;
}

void FibonacciSequence::end() noexcept 
{
	fPrevious = fCurrent;
	fCurrent = 0;
}