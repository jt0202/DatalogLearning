/*
 * Souffle - A Datalog Compiler
 * Copyright (c) 2013, 2015, Oracle and/or its affiliates. All rights reserved
 * Licensed under the Universal Permissive License v 1.0 as shown at:
 * - https://opensource.org/licenses/UPL
 * - <souffle root>/licenses/SOUFFLE-UPL.txt
 */

/************************************************************************
 *
 * @file SrcLocation.h
 *
 * Structures to describe a location within input code.
 *
 ***********************************************************************/

#pragma once

#include <memory>
#include <ostream>
#include <sstream>
#include <string>

namespace souffle {

/** A class locating a single point in an input file */
struct Point {
    /** The line in the source file */
    int line;

    /** The column in the source file */
    int column;

    /** A comparison for points */
    bool operator<(const Point& other) const {
        return line < other.line || (line == other.line && column < other.column);
    }

    bool operator>(const Point& other) const {
        return other < *this;
    }

    void print(std::ostream& out) const {
        out << line << ":" << column;
    }

    /** Enables locations to be printed */
    friend std::ostream& operator<<(std::ostream& out, const Point& loc) {
        loc.print(out);
        return out;
    }
};

/** A recursive include stack. */
struct IncludeStack {
    explicit IncludeStack(std::shared_ptr<IncludeStack> parent, Point includePos, const std::string& physical,
            const std::string& reported)
            : ParentStack(parent), IncludePos(includePos), Physical(physical), Reported(reported) {}

    /** The parent file. */
    const std::shared_ptr<IncludeStack> ParentStack;

    /** The position of the include directive in the parent file. */
    const Point IncludePos;

    /** This file. */
    const std::string Physical;

    /** The reported path for this file. */
    const std::string Reported;
};

/** A class describing a range in an input file */
class SrcLocation {
public:
    /** The file referred to */
    std::shared_ptr<IncludeStack> file;

    /** The start location */
    Point start = {};

    /** The End location */
    Point end = {};

    /** Return the shortened reported file name */
    std::string getReportedFilename() const;

    /** Return the full reported file path */
    const std::string& getReportedPath() const;

    /** A comparison for source locations */
    bool operator<(const SrcLocation& other) const;

    /** Extend the current source location with the other, only if both have
     * the same include stack */
    SrcLocation& operator+=(const SrcLocation& other);

    /** Set the source location's file (hence include stack) */
    void setFile(const std::shared_ptr<IncludeStack>& file);

    /** An extended string describing this location in a end-user friendly way */
    std::string extloc() const;

    void print(std::ostream& out) const;

    /** Enables ranges to be printed */
    friend std::ostream& operator<<(std::ostream& out, const SrcLocation& range) {
        range.print(out);
        return out;
    }
};

/** Information struct for scanner */
struct ScannerInfo {
    /** Scanner's current location */
    SrcLocation yylloc;

    /** Include stack of scanned files, top is the current scanned file */
    std::shared_ptr<IncludeStack> yyfilename;

    /** Location of last .include directive */
    SrcLocation LastIncludeDirectiveLoc;

    /** Extent of the current comment */
    SrcLocation CommentExtent;

    /** Content of the current comment */
    std::stringstream CommentContent;

    /** Push a file on the include stack */
    void push(const std::string& NewFile, const SrcLocation& IncludeLoc);

    /** Pop a file from the include stack */
    void pop();

    /** Set the reported path for the current file */
    void setReported(const std::string& Reported);
};

}  // end of namespace souffle
