// Question 8 : write here the buggy function without errors
#include <stdio.h>
#include <stdarg.h>
#include <signal.h>

#define KNOT_TO_KMH 1.852

int knot_to_kmh_str(float not, size_t size, char * format, char * kmh_str)
	{ 	
		float kmh = KNOT_TO_KMH*not;
		snprintf(kmh_str, size, format, kmh);
		return kmh;
	}

// Question 12 : write printf with a signal handler


void handler(int signal_number)
	{
		fprintf(stdout, "Pika Pika\n");
	}
	
int printf(const char*format, ...)
	{
		struct sigaction action;
		action.sa_handler = handler;
		sigemptyset(& (action.sa_mask));
		action.sa_flags = 0;
		sigaction(SIGINT, & action, NULL);
	}
