#pragma once
#pragma warning(disable : 4996)
using namespace std;
#include <iostream>
#include <stack>
#include <string>
#include"time.h"
#include<iomanip>
#include <vector>
#include<queue>
#include"clsDate.h"
using namespace std;
class cls_queue_line
{
private:
	int _total_tickets;
	int _average_serve_time;
	string _pref="";
	class cls_ticket
	{
	private:
		string _time;
		string _prefix;
		int _waiting_clients;
		int _serve_time;
		int _num_of_ticket;
	public:


		cls_ticket(string pref, int waiting_client, int serv_time, int num)
		{
			_time = clsDate::get_time_string();
			_prefix = pref;
			_waiting_clients = waiting_client;
			_serve_time = serv_time;
			_num_of_ticket = num;
		}

		string ticket_time()
		{
			return _time;
		}
		string full_prefix()
		{
			return _prefix + to_string(_num_of_ticket);
		}
		int current_num()
		{
			return _num_of_ticket;
		}
		int ticket_serve_time()
		{
			return _waiting_clients * _serve_time;
		}
		int num_waiting()
		{
			return _waiting_clients;
		}
		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << full_prefix();
			cout << "\n\n\t\t\t    " << ticket_time();
			cout << "\n\t\t\t    Wating Clients = " << num_waiting();
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ticket_serve_time() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";


		}
		
	};

public:
	queue<cls_ticket>que_line;

	cls_queue_line(string pref,  int serve_time)
	{
		_total_tickets = 0;
		_pref = pref;
		_average_serve_time = serve_time;
	}

	void issue_ticket()
	{
		_total_tickets++;
		cls_ticket q1(_pref, waiting_clients(), _average_serve_time, _total_tickets);
		que_line.push(q1);
	}

	int waiting_clients()
	{
		return que_line.size();

	}

	void serve_next()
	{
		que_line.pop();
	}

	int served_clients()
	{
		return _total_tickets - waiting_clients();
	}

	void print_info()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _pref;
		cout << "\n\t\t\t    Total Tickets   = " << _total_tickets;
		cout << "\n\t\t\t    Served Clients  = " << served_clients();
		cout << "\n\t\t\t    Wating Clients  = " << waiting_clients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
	}

	void print_all_tickets()
	{
		queue<cls_ticket> temp = que_line;
		while (!temp.empty())
		{
			temp.front().Print();
			temp.pop();
		}
	}

};

//private:
//	struct info
//	{
//		string _pref;
//		int _waiting = 0;
//		string _time;
//	};
//
//	int clients = 0;
//	string general_pref;
//	int time_wait;
//	int _surved = 0;
//	info data;
//	vector<info> all_data;
//public:
//	cls_queue_line(string pref, int time)
//	{
//		general_pref = pref;
//		time_wait = time;
//	}

//
//	void issue_ticket()
//	{
//
//		clients++;
//		data._time = get_time_string();
//		data._pref = general_pref + to_string(clients);
//		all_data.push_back(data);
//		data._waiting++;
//	}
//
//	void print_queue_info()
//	{
//		cout << left << setw(10) << "Queue info" << endl;
//		cout << left << setw(8) << "-----------------------" << endl;
//		cout << left << setw(10) << "prefix: " << general_pref << endl;
//		cout << left << setw(10) << "surved: " << _surved << endl;
//		cout << left << setw(10) << "waiting: " << clients << endl;
//		cout << left << setw(8) << "-----------------------" << endl;
//
//	}
//
//	void print_all_tickets()
//	{
//
//		for (int i = 0;i < all_data.size();i++)
//		{
//			cout << left << setw(8) << "-----------------------" << endl;
//			cout << left << setw(10) << "prefix: " << all_data[i]._pref << endl;
//			cout << left << setw(10) << all_data[i]._time << endl;
//			cout << left << setw(10) << "waiting clients: " << all_data[i]._waiting << endl;
//			cout << left << setw(10) << "serve time in: " << i * time_wait << endl;
//			cout << left << setw(8) << "-----------------------" << endl;
//		}
//	}
//
//	void serve_next_client()
//	{
//		all_data.erase(all_data.begin());
//		clients--;
//		_surved++;
//		for (info& n : all_data)
//		{
//			n._waiting--;
//		}
//	}

