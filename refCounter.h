
//
// CST 211 - Assignment #1
//
// John Zimmerman
// 
//
// File : refCounter.h
//
// Reference counting class declaractions.
//

#ifndef refCounter_H
#define refCounter_H

//
// Reference counting class declaration
//
class RefCounter
{
public:

	RefCounter();
	RefCounter(const RefCounter  &rhs);
	~RefCounter();
	bool  onlyInstance() const;

	RefCounter &operator=(const RefCounter &rhs);

private:

	int  *m_cnt;

	void  decrement();
	void  copy(const RefCounter  &rhs);
};


#endif
