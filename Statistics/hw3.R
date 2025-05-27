# 14-2.18
o <- c(83, 61, 56)
e <- rep(sum(o) / 3, 3)

n <- length(o)

critical_value <- qchisq(0.05, df = n - 1, lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 5.991465
chi_statistic # [1] 6.19

p1 <- o[1] / sum(o)
z_value <- qnorm(p = 0.05 / 2, lower.tail = FALSE)

p1 - z_value * sqrt(p1 * (1 - p1) / sum(o)) # [1] 0.3467135
p1 + z_value * sqrt(p1 * (1 - p1) / sum(o)) # [1] 0.4832865


# 14-2.22
o <- c(24, 36, 27, 26, 32, 26, 29)
e <- rep(sum(o) / 7, 7)

n <- length(o)

chi_statistic <- sum((o - e)^2 / e)
critical_value <- qchisq(0.05, df = n - 1, lower.tail = FALSE)

chi_statistic # [1] 3.63
critical_value # [1] 12.59159


# 14-2.26
o <- c(70, 72, 61, 118, 108, 85)
e <- c(sum(o) * 0.13, sum(o) * 0.14, sum(o) * 0.13, sum(o) * 0.24, sum(o) * 0.20, sum(o) * 0.16)

n <- length(o)

chi_statistic <- sum((o - e)^2 / e)
critical_value <- qchisq(0.05, df = n - 1, lower.tail = FALSE)

chi_statistic # [1] 1.246834
critical_value # [1] 11.0705


# 14-3.18
o <- matrix(c(
  67, 26, 16,
  128, 63, 46
), nrow = 2, ncol = 3, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 3, byrow = TRUE)

chi_statistic <- sum((o - e)^2 / e)
critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)

chi_statistic # [1] 1.885669
critical_value # [1] 5.991465


# 14-3.22
o <- matrix(c(
  42, 309, 31,
  64, 246, 46,
  20, 115, 27
), nrow = 3, ncol = 3, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o),
  rowSums(o)[3] * colSums(o) / sum(o)
), nrow = 3, ncol = 3, byrow = TRUE)

critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 9.487729
chi_statistic # [1] 18.71095


# 14-3.26
# (a)
o <- matrix(c(
  62, 13, 11, 76,
  10, 7, 7, 14
), nrow = 2, ncol = 4, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 4, byrow = TRUE)

critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 7.814728
chi_statistic # [1] 9.869324

# (b)
o[2, 1] / colSums(o)[1] # [1] 0.1388889
o[2, 2] / colSums(o)[2] # [1] 0.35
o[2, 3] / colSums(o)[3] # [1] 0.3888889
o[2, 4] / colSums(o)[4] # [1] 0.1555556


# 14-4.8
# (a)
o <- matrix(c(
  134, 66,
  86, 114,
  49, 151
), nrow = 3, ncol = 2, byrow = TRUE)

o / 200
#       [,1]  [,2]
# [1,] 0.670 0.330
# [2,] 0.430 0.570
# [3,] 0.245 0.755

# (b)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o),
  rowSums(o)[3] * colSums(o) / sum(o)
), nrow = 3, ncol = 2, byrow = TRUE)

critical_value <- qchisq(0.01, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 9.21034
chi_statistic # [1] 73.43748


# 14-4.16
# (a)
o <- matrix(c(
  73, 51,
  27, 49
), nrow = 2, ncol = 2, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 2, byrow = TRUE)

critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 3.841459
chi_statistic # [1] 10.27165

# (b)
p1 <- o[1, 1] / colSums(o)[1]
p2 <- o[1, 2] / colSums(o)[2]
p <- rowSums(o)[1] / sum(o)
n <- colSums(o)[1]

critical_value <- qnorm(0.05, lower.tail = FALSE)
z_statistic <- (p1 - p2) / sqrt(p * (1 - p) * (1 / n + 1 / n))

critical_value # [1] 1.644854
z_statistic # [1] 3.204941


# case study
# 1.
o <- matrix(c(
  64, 16, 20,
  31, 45, 24
), nrow = 2, ncol = 3, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 3, byrow = TRUE)

critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 5.991465
chi_statistic # [1] 25.61368

# 2.
o <- matrix(c(
  42, 24, 12, 12, 10,
  55, 18, 11, 8, 8
), nrow = 2, ncol = 5, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 5, byrow = TRUE)

chi_statistic <- sum((o - e)^2 / e)
critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)

chi_statistic # [1] 3.665111
critical_value # [1] 9.487729

# 3.
o <- matrix(c(
  47, 30, 24,
  53, 70, 76
), nrow = 2, ncol = 3, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 3, byrow = TRUE)

critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)
chi_statistic <- sum((o - e)^2 / e)

critical_value # [1] 5.991465
chi_statistic # [1] 12.7469

# 4.
o <- matrix(c(
  59, 41,
  63, 37
), nrow = 2, ncol = 2, byrow = TRUE)
e <- matrix(c(
  rowSums(o)[1] * colSums(o) / sum(o),
  rowSums(o)[2] * colSums(o) / sum(o)
), nrow = 2, ncol = 2, byrow = TRUE)

chi_statistic <- sum((o - e)^2 / e)
critical_value <- qchisq(0.05, df = (nrow(o) - 1) * (ncol(o) - 1), lower.tail = FALSE)

chi_statistic # [1] 0.3362757
critical_value # [1] 3.841459


# 15-1.16
x <- matrix(c(
  84, 128, 168, 92, 184, 92, 76, 104, 72, 180, 144, 120,
  140, 184, 368, 96, 480, 188, 480, 244, 440, 380, 480, 196
), nrow = 2, ncol = 12, byrow = TRUE)
r <- matrix(as.vector(rank(t(x))), nrow = 2, ncol = 12, byrow = TRUE)
#      [,1] [,2] [,3] [,4] [,5] [,6] [,7] [,8] [,9] [,10] [,11] [,12]
# [1,]    3  9.0   12  4.5 14.5  4.5    2    7    1    13    11     8
# [2,]   10 14.5   19  6.0 23.0 16.0   23   18   21    20    23    17

t1 <- rowSums(r)[1]
n1 <- length(r[1, ])
n2 <- length(r[2, ])

z_statistic <- (t1 - n1 * (n1 + n2 + 1) / 2) / sqrt(n1 * n2 * (n1 + n2 + 1) / 12)
critical_value <- qnorm(0.95, lower.tail = FALSE)

z_statistic # [1] -3.492969
critical_value # [1] -1.644854


# 15-2.6(b)
n <- 25 - 10

sum(dbinom(7:n, size = n, prob = 0.5)) # [1] 0.6963806


# 15-2.8
n <- 35

sum(dbinom(21:n, size = n, prob = 0.5)) # [1] 0.1552523


# 15-4.14
x1 <- c(126, 117, 115, 118, 118, 128, 125, 120)
x2 <- c(130, 118, 125, 120, 121, 125, 130, 120)

d <- x1 - x2
r <- rank(abs(d))
# [1] 6.0 2.0 8.0 3.0 4.5 4.5 7.0 1.0

sum(r[d > 0]) # [1] 4.5


# 15-5.10
x <- matrix(c(
  0.33, 0.29, 0.21, 0.32, 0.25,
  0.28, 0.41, 0.34, 0.39, 0.27,
  0.21, 0.30, 0.26, 0.33, 0.31
), nrow = 3, ncol = 5, byrow = TRUE)
r <- matrix(as.vector(rank(t(x))), nrow = 3, ncol = 5, byrow = TRUE)

n <- length(x)
k <- nrow(x)

h_statistic <- 12 / (n * (n + 1)) * sum(rowSums(r)^2 / (n / 3)) - 3 * (n + 1)
critical_value <- qchisq(0.05, df = k - 1, lower.tail = FALSE)

h_statistic # [1] 2.54
critical_value # [1] 5.991465


# 15-6.8
# (a)
x <- matrix(c(
  3.99, 4.29, 4.49, 2.99, 3.19, 2.99, 5.99, 5.15,
  2.79, 4.29, 5.49, 3.19, 3.49, 3.49, 6.49, 5.49,
  1.99, 3.99, 4.49, 2.79, 3.49, 3.49, 5.79, 4.79,
  1.78, 2.50, 3.15, 1.48, 1.48, 1.58, 5.14, 4.34
), nrow = 4, ncol = 8, byrow = TRUE)
r <- matrix(as.vector(apply(x, 2, rank)), nrow = 4, ncol = 8, byrow = FALSE)

k <- nrow(x)
b <- ncol(x)

critical_value <- qchisq(0.05, df = k - 1, lower.tail = FALSE)
f_statistic <- 12 / (b * k * (k + 1)) * sum(rowSums(r)^2) - 3 * b * (k + 1)

critical_value # [1] 7.814728
f_statistic # [1] 18.2625

# (b)
p_value <- pchisq(f_statistic, df = k - 1, lower.tail = FALSE)
p_value # [1] 0.0003882818


# 15-6.10(c)
x <- matrix(c(
  4.8, 8.1, 5.0, 7.9, 3.9,
  2.2, 9.2, 2.6, 9.4, 7.4,
  6.8, 6.6, 3.6, 5.3, 2.1,
  6.2, 9.6, 6.5, 8.5, 2.0
), nrow = 4, ncol = 5, byrow = TRUE)
r <- matrix(as.vector(apply(x, 2, rank)), nrow = 4, ncol = 5, byrow = FALSE)

k <- nrow(x)
b <- ncol(x)

f_statistic <- 12 / (b * k * (k + 1)) * sum(rowSums(r)^2) - 3 * b * (k + 1)
critical_value <- qchisq(0.05, df = k - 1, lower.tail = FALSE)

f_statistic # [1] 1.56
critical_value # [1] 7.814728


# 15-7.12
x <- c(9, 13, 5, 7, 12, 6, 4, 5, 3)
y <- c(33.15, 33.33, 33.50, 33.55, 33.73, 33.86, 33.90, 34.15, 34.90)

rx <- rank(x)
ry <- rank(y)

n <- length(x)

sxy <- sum(rx * ry) - sum(rx) * sum(ry) / n
sxx <- sum(rx^2) - sum(rx)^2 / n
syy <- sum(ry^2) - sum(ry)^2 / n

sxy / sqrt(sxx * syy) # [1] -0.7447764


# 15-7.16
x <- c(9, 6, 7, 7, 5, 8, 2, 6, 1, 10, 9, 3)
y <- c(0.22, 0.16, 0.17, 0.14, 0.12, 0.19, 0.10, 0.12, 0.05, 0.20, 0.16, 0.09)

rx <- rank(x)
ry <- rank(y)

n <- length(x)

sxy <- sum(rx * ry) - sum(rx) * sum(ry) / n
sxx <- sum(rx^2) - sum(rx)^2 / n
syy <- sum(ry^2) - sum(ry)^2 / n

sxy / sqrt(sxx * syy) # [1] 0.911818
