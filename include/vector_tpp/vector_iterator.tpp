/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.tpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkintana <gkintana@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:37:34 by gkintana          #+#    #+#             */
/*   Updated: 2022/09/10 13:38:14 by gkintana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
** @brief    checks if value at the position ft iterator and std iterator are currently
**           at are equal
**
** @param ft             address of container with ft namespace
** @param std            address of container with std namespace
** @param offset         integer which represents a value to be added or subtracted
**                       to the iterator's position
** @param option         integer that indicates which type of iterator or reverse
**                       iterator will be compared with the std equivalent
*/
template <typename T>
void vectorTester::compareIterToStd(ft::vector<T> &ft, std::vector<T> &std,
                                    int offset, int option) {
	if (option == BEGIN) {
		*(ft.begin() + offset) == *(std.begin() + offset) ? addOK() : addKO();
	} else if (option == END) {
		*(ft.end() - offset) == *(std.end() - offset) ? addOK() : addKO();
	} else if (option == RBEGIN) {
		*(ft.rbegin() + offset) == *(std.rbegin() + offset) ? addOK() : addKO();
	} else if (option == REND) {
		*(ft.rend() - offset) == *(std.rend() - offset) ? addOK() : addKO();
	}
}

template <typename T>
void vectorTester::iterLoop(ft::vector<T> &ft, std::vector<T> &std,
                            FT_ITER start, FT_ITER end) {
	size_t pos = 0;
	for (FT_ITER temp = ft.begin(); temp != start; temp++) {
		pos++;
	}

	STD_ITER std_iter = std.begin() + pos;
	for (FT_ITER ft_iter = start; ft_iter != end; ft_iter++) {
		*ft_iter == *std_iter++ ? addOK() : addKO();
	}
}

template <typename T>
void vectorTester::revIterLoop(ft::vector<T> &ft, std::vector<T> &std,
                               FT_REV_ITER start, FT_REV_ITER end) {
	size_t pos = 0;
	for (FT_REV_ITER temp = ft.rend(); temp != start; temp--) {
		pos++;
	}

	STD_REV_ITER std_iter = std.rend() - pos;
	for (FT_REV_ITER ft_iter = start; ft_iter != end; ft_iter--) {
		*ft_iter == *std_iter-- ? addOK() : addKO();
	}
}
