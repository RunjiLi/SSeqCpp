#ifndef MILNOR_BASIS_HPP
#define MILNOR_BASIS_HPP

#include<vector>
#include<array>
#include<iostream>
#include<set>
//#include<unordered_set>	//the unorded set doesn't work for some reason

const size_t CACHE_SIZE = 128;
const size_t MATRIX_SIZE = 8;
const size_t MAX_DEGREE = 276;
const int p = 2; //avoid magic numbers, although the program depends on p=2

/**
The class used to calculate product structure with milnor basis 
*/
class prod_calculator 
{
public:
	
	prod_calculator() : cache(get_cache()), prod({}) {}

	/**
	The function that calculates the product given sequences R and S
	@param R: R sequence
	@param S: S sequence
	returns a set containing all sequences T in the summation of product
	*/
	std::set<std::array<int, MATRIX_SIZE>> get_prod(const std::array<int, MATRIX_SIZE>& R, const std::array<int, MATRIX_SIZE>& S);

private:

	void calculate_product(std::array<int, MATRIX_SIZE>& R, std::array<int, MATRIX_SIZE>& S, std::array<int, MATRIX_SIZE>& TX, int depth);

	std::set<std::array<int, MATRIX_SIZE>> prod; //want to use unordered set

	std::array<std::vector<std::array<uint8_t, MATRIX_SIZE - 1>>, CACHE_SIZE> cache;

	std::array<std::array<bool, MATRIX_SIZE - 1>, MATRIX_SIZE - 1> generate_matrix(const  std::array<int, MATRIX_SIZE - 1>& seq);
	
	/**
	The procedure that generates cache for computing Milnor basis
	@param cache: stores the generated cache, should be initialized to an array of empty vectors
	@param seq: auxlliary sequence for generating matrix
	@param depth: depth for search, should input 1
	*/
	void generate_cache(std::array<std::vector<std::array<std::array<bool, MATRIX_SIZE - 1>, MATRIX_SIZE - 1> >, CACHE_SIZE>& cache, std::array<int, MATRIX_SIZE - 1>& seq, int depth);

	std::array<std::vector<std::array<uint8_t, MATRIX_SIZE - 1>>, CACHE_SIZE> get_cache();

};

#endif // !MILNOR_BASIS_HPP