
#include <gflags/gflags.h>

#include <iostream>

#include "cnf2graph/CNFReader.h"
#include "cnf2graph/CNFModel.h"

DEFINE_string(input, "", "Required: input cnf file.");


static const char kUsage[] =
    "Usage: see flags.\n"
    "This program solves a given CNF sat problem in cnf format.";

int main( int argc, char *argv[]) {
    gflags::SetUsageMessage(kUsage);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    cnf2graph::CNFModel model;
    cnf2graph::CNFReader reader;
    reader.load(FLAGS_input, &model);

    model.summarize();
    std::cout << "Hello" << std::endl;

    return 0;
}
