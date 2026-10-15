/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seilkiv <seilkiv@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:29:11 by seilkiv           #+#    #+#             */
/*   Updated: 2026/10/15 14:08:10 by seilkiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "--- Successful signature ---" << std::endl;
    {
        Bureaucrat alice("Alice", 10);
        Form form("Tax form", 20, 50);

        std::cout << alice << std::endl;
        std::cout << form << std::endl;
        alice.signForm(form);
        std::cout << form << std::endl;
    }

    std::cout << std::endl << "--- Insufficient grade ---" << std::endl;
    {
        Bureaucrat bob("Bob", 50);
        Form form("Important form", 25, 50);

        std::cout << bob << std::endl;
        std::cout << form << std::endl;
        bob.signForm(form);
        std::cout << form << std::endl;
    }

    std::cout << std::endl << "--- Invalid Bureaucrat grades ---" << std::endl;
    try
    {
        Bureaucrat tooHigh("Too high", 0);
        std::cout << tooHigh << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Bureaucrat error: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat tooLow("Too low", 151);
        std::cout << tooLow << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Bureaucrat error: " << e.what() << std::endl;
    }

    std::cout << std::endl << "--- Invalid Form grades ---" << std::endl;
    try
    {
        Form tooHigh("Invalid high form", 0, 10);
        std::cout << tooHigh << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Form error: " << e.what() << std::endl;
    }

    try
    {
        Form tooLow("Invalid low form", 10, 151);
        std::cout << tooLow << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Form error: " << e.what() << std::endl;
    }

    return 0;
}
