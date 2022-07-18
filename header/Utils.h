//
// Created by eason on 2022/7/15.
//

#ifndef JNIDEMO_UTILS_H
#define JNIDEMO_UTILS_H

#include <thread>
#include <sstream>
#include <sys/cdefs.h>

__BEGIN_DECLS

typedef unsigned long long ULL;

static inline std::string getThreadIdOfString(const std::thread::id &id) {
    std::stringstream sin;
    sin << id;
    return sin.str();
}

/**
 *
 * @param id
 * @return
 */
static inline ULL getThreadIdOfULL(const std::thread::id &id) {
    return std::stoull(getThreadIdOfString(id));
}

__END_DECLS
#endif //JNIDEMO_UTILS_H
