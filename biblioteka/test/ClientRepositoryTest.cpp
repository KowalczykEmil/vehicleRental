//
// Created by student on 19.06.2020.
//
#include <boost/test/unit_test.hpp>
#include "model/clientRepository.h"
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include "model/clientGold.h"
#include "model/clientBronze.h"
#include "model/clientSilver.h"
#include "model/client.h"
using boost::test_tools::output_test_stream;


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(ClientRepositoryAddClientCase)
    {
        output_test_stream output;
        output_test_stream output2;
        ClientPtr klient = make_shared<Client>("Emil", "Kowalczyk", "1234", "a", 2, "b", 3);
        ClientRepository repo;
        repo.addClient(klient);
        output << repo.clientRepositoryInfo();
        output2 <<"1. Emil Kowalczyk" <<endl;
        BOOST_TEST( output.is_equal(output2.str()));
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemoveIntCase)
    {
        output_test_stream output;
        output_test_stream output2;
        ClientPtr klient = make_shared<Client>("Emil", "Kowalczyk", "1234", "a", 2, "b", 3);
        ClientRepository repo;
        repo.addClient(klient);
        ClientPtr klient2 = make_shared<Client>("Dominik", "Swiader", "12324", "a", 2, "b", 3);
        repo.addClient(klient2);
        repo.removeClient(1);
        output << repo.clientRepositoryInfo();
        output2 <<"1. Dominik Swiader" <<endl;
        BOOST_TEST( output.is_equal(output2.str()));
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryRemovePtrCase)
    {
        output_test_stream output;
        output_test_stream output2;
        ClientPtr klient = make_shared<Client>("Emil", "Kowalczyk", "1234", "a", 2, "b", 3);
        ClientRepository repo;
        repo.addClient(klient);
        ClientPtr klient2 = make_shared<Client>("Dominik", "Swiader", "12324", "a", 2, "b", 3);
        repo.addClient(klient2);
        repo.removeClient(klient);
        output << repo.clientRepositoryInfo();
        output2 <<"1. Dominik Swiader" <<endl;
        BOOST_TEST( output.is_equal(output2.str()));
    }

    BOOST_AUTO_TEST_CASE(ClientRepositoryChangeTypeCase)
    {
        output_test_stream output;
        output_test_stream output2;
        ClientPtr klient = make_shared<Client>("Emil", "Kowalczyk", "1234", "a", 2, "b", 3);
        ClientRepository repo;
        repo.addClient(klient);
        ClientTypePtr type(new ClientGold);
        repo.changeType(klient, type);
        output << repo.clientRepositoryInfo();
        output2 <<"1. Emil Kowalczyk [GOLD]" <<endl;
        BOOST_TEST( output.is_equal(output2.str()));
    }


BOOST_AUTO_TEST_SUITE_END()