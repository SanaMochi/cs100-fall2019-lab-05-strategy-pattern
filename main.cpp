#include "base.hpp"
#include "op.hpp"
#include "Mult.hpp"
#include "Div.hpp"
#include "Pow.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "rand.hpp"
#include "container.hpp"

int main(){
	Base* b1 = new Op(5);
	VectorContainer c1 ;
	c1.add_element(b1);
	return 0;
}
