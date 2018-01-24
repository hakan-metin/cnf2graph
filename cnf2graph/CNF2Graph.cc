
#include <gflags/gflags.h>

#include <iostream>

#include "cnf2graph/CNFReader.h"
#include "cnf2graph/CNFModel.h"
#include "cnf2graph/CNFModelExport.h"
#include "cnf2graph/CNFGraph.h"

DEFINE_string(input, "", "Required: input cnf file.");

DEFINE_bool(print_sanitize, false, "print CNF without duplicates");

static const char kUsage[] =
    "Usage: see flags.\n"
    "This program solves a given CNF sat problem in cnf format.";

int main( int argc, char *argv[]) {
    gflags::SetUsageMessage(kUsage);
    gflags::ParseCommandLineFlags(&argc, &argv, true);

    cnf2graph::CNFModel model;
    cnf2graph::CNFModelExport model_export;
    cnf2graph::CNFReader reader;
    cnf2graph::CNFGraph graph;

    reader.load(FLAGS_input, &model);

    if (FLAGS_print_sanitize) {
        model_export.print(model);
        return 0;
    }
    model.summarize();

    graph.assign(model);

    return 0;
}
