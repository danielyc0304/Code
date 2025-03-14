# 10-1.2
t_value <- qt(p = 0.05, df = 20, lower.tail = FALSE)

t_value # [1] 1.724718


# 10-1.8
t_value <- qt(p = 0.05, df = 8)

t_value # [1] -1.859548


# 10-2.10
p_value <- pt(q = 3.21, df = 16, lower.tail = FALSE)

p_value # [1] 0.002730849


# 10-2.20
x_bar <- 69.7
mu <- 74
s <- 16
n <- 25

critical_value1 <- qt(p = 1 - 0.05 / 2, df = n - 1, lower.tail = FALSE)
t_statistic <- (x_bar - mu) / (s / sqrt(n))
critical_value2 <- qt(p = 0.05 / 2, df = n - 1, lower.tail = FALSE)

critical_value1 # [1] -2.063899
t_statistic # [1] -1.34375
critical_value2 # [1] 2.063899


# 10-2.22
data <- c(29.0, 24.1, 23.7, 19.6, 27.5, 28.7, 28.0, 23.8, 18.9, 23.9, 21.6, 25.9, 27.4)

x_bar <- mean(data)
s <- sd(data)
n <- length(data)

t_value <- qt(p = 0.05 / 2, df = n - 1, lower.tail = FALSE)

x_bar - t_value * s / sqrt(n) # [1] 22.75801
x_bar + t_value * s / sqrt(n) # [1] 26.79584

# t.test(x = data)$conf.int


# 10-2.26
# (a)
data <- c(
  103.768, 88.602, 73.003, 123.086, 91.052, 92.295, 61.675, 90.677, 84.023, 76.014,
  100.615, 88.017, 71.210, 82.115, 89.222, 102.754, 108.579, 73.154, 106.755, 90.479
)

x_bar <- mean(data)
mu <- 100
s <- sd(data)
n <- length(data)

t_statistic <- (x_bar - mu) / (s / sqrt(n))
critical_value <- qt(p = 1 - 0.01, df = n - 1, lower.tail = FALSE)

t_statistic # [1] -3.044309
critical_value # [1] -2.539483

# t.test(x = data, mu = mu, alternative = "less", conf.level = 0.99)

# (b)
t_value <- qt(p = 0.01, df = n - 1, lower.tail = FALSE)

x_bar + t_value * s / sqrt(n) # [1] 98.31765

# t.test(x = data, alternative = "less", conf.level = 0.99)$conf.int


# 10-2.33(b)
data <- c(
  148, 304, 300, 240, 368, 139, 203, 249, 265, 229,
  303, 315, 174, 209, 253, 169, 170, 254, 212, 255,
  262, 284, 275, 229, 261, 239, 254, 222, 273, 299,
  278, 227, 220, 260, 221, 247, 178, 204, 250, 256,
  305, 225, 306, 184, 242, 282, 311, 271, 276, 248
)

x_bar <- mean(data)
s <- sd(data)
n <- length(data)

t_value <- qt(p = 0.05 / 2, df = n - 1, lower.tail = FALSE)

x_bar - t_value * s / sqrt(n) # [1] 233.6526
x_bar + t_value * s / sqrt(n) # [1] 260.2674

# t.test(x = data)$conf.int


# 10-2.34
data <- c(
  148, 304, 300, 240, 368, 139, 203, 249, 265, 229,
  303, 315, 174, 209, 253, 169, 170, 254, 212, 255,
  262, 284, 275, 229, 261, 239, 254, 222, 273, 299,
  278, 227, 220, 260, 221, 247, 178, 204, 250, 256,
  305, 225, 306, 184, 242, 282, 311, 271, 276, 248
)

x_bar <- mean(data)
s <- sd(data)
n <- length(data)

z_value <- abs(qnorm(p = 0.05 / 2))

x_bar - z_value * s / sqrt(n) # [1] 233.9812
x_bar + z_value * s / sqrt(n) # [1] 259.9388

# t.test(x = data)$conf.int


# 10-3.14
# (b)
x1_bar <- 1.26
s1 <- 0.32
n1 <- 7

x2_bar <- 0.78
s2 <- 0.78
n2 <- 7

d <- 0
pooled_variance <- ((n1 - 1) * s1^2 + (n2 - 1) * s2^2) / (n1 + n2 - 2)

t_statistic <- (x1_bar - x2_bar - d) / sqrt(pooled_variance * (1 / n1 + 1 / n2))
critical_value <- qt(p = 0.05, df = n1 + n2 - 2, lower.tail = FALSE)

t_statistic # [1] 1.506318
critical_value # [1] 1.782288

# (c)
p_value <- pt(q = t_statistic, df = n1 + n2 - 2, lower.tail = FALSE)

p_value # [1] 0.07892443


# 10-3.18
# (a)
data1 <- c(0.011, 0.013, 0.013, 0.015, 0.014, 0.013, 0.010, 0.013, 0.011, 0.012)
data2 <- c(0.011, 0.016, 0.013, 0.012, 0.015, 0.012, 0.017, 0.013, 0.014, 0.015)

x1_bar <- mean(data1)
s1 <- sd(data1)
n1 <- length(data1)

x2_bar <- mean(data2)
s2 <- sd(data2)
n2 <- length(data2)

d <- 0
pooled_variance <- ((n1 - 1) * s1^2 + (n2 - 1) * s2^2) / (n1 + n2 - 2)

critical_value1 <- qt(p = 1 - 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)
t_statistic <- (x1_bar - x2_bar - d) / sqrt(pooled_variance * (1 / n1 + 1 / n2))
critical_value2 <- qt(p = 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)

critical_value1 # [1] -2.100922
t_statistic # [1] -1.676741
critical_value2 # [1] 2.100922

# t.test(x = data1, y = data2, var.equal = TRUE)

# (b)
t_value <- qt(p = 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)

(x1_bar - x2_bar) - t_value * sqrt(pooled_variance * (1 / n1 + 1 / n2)) # [1] -0.002928873
(x1_bar - x2_bar) + t_value * sqrt(pooled_variance * (1 / n1 + 1 / n2)) # [1] 0.0003288733

# t.test(x = data1, y = data2, var.equal = TRUE)$conf.int


# 10-3.24
data1 <- c(18.3, 15.8, 18.0, 18.0, 20.8)
data2 <- c(17.7, 18.3, 16.7, 14.8, 19.1)

x1_bar <- mean(data1)
s1 <- sd(data1)
n1 <- length(data1)

x2_bar <- mean(data2)
s2 <- sd(data2)
n2 <- length(data2)

d <- 0
pooled_variance <- ((n1 - 1) * s1^2 + (n2 - 1) * s2^2) / (n1 + n2 - 2)

critical_value1 <- qt(p = 1 - 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)
t_statistic <- (x1_bar - x2_bar - d) / sqrt(pooled_variance * (1 / n1 + 1 / n2))
critical_value2 <- qt(p = 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)

critical_value1 # [1] -2.306004
t_statistic # [1] 0.7914259
critical_value2 # [1] 2.306004

# t.test(x = data1, y = data2, var.equal = TRUE)


# 10-4.10
data1 <- c(4, 5, 5, 4, 3, 6, 2)
data2 <- c(7, 8, 3, 5, 4, 5, 5)

d <- data1 - data2

d_bar <- mean(d)
s <- sd(d)
n <- length(d)

critical_value <- qt(p = 1 - 0.05, df = n - 1, lower.tail = FALSE)
t_statistic <- (d_bar - 0) / (s / sqrt(n))

critical_value # [1] -1.94318
t_statistic # [1] -1.485563

# t.test(x = data1, y = data2, paired = TRUE, alternative = "less")


# 10-4.14
# (a)
data1 <- c(254.26, 240.62, 231.90, 234.13)
data2 <- c(256.03, 255.65, 255.12, 261.18)

d <- data1 - data2

d_bar <- mean(d)
s <- sd(d)
n <- length(d)

t_statistic <- (d_bar - 0) / (s / sqrt(n))
critical_value <- qt(p = 1 - 0.05, df = n - 1, lower.tail = FALSE)

t_statistic # [1] -2.998229
critical_value # [1] -2.353363

# t.test(x = data1, y = data2, paired = TRUE, alternative = "less")

# (b)
p_value <- 1 - pt(q = t_statistic, df = n - 1, lower.tail = FALSE)

p_value # [1] 0.02887517

# (c)
t_value <- qt(p = 0.01 / 2, df = n - 1, lower.tail = FALSE)

d_bar - t_value * s / sqrt(n) # [1] -49.4326
d_bar + t_value * s / sqrt(n) # [1] 15.8976

# t.test(x = data1, y = data2, paired = TRUE, conf.level = 0.99)$conf.int


# 10-5.2
chi_value <- qchisq(p = 0.95, df = 25 - 1, lower.tail = FALSE)

chi_value # [1] 13.84843


# 10-5.12
# (a)
data1 <- c(
  28, 22, 20, 18, 31, 27, 20, 21,
  17, 15, 25, 21, 22, 20, 31, 22
)
data2 <- c(
  13.8, 13.2, 11.4, 17.7, 11.1, 16.1, 12.6, 17.2,
  12.5, 12.2, 10.7, 12.3, 15.8, 11.8, 10.7, 8.7
)

x1_bar <- mean(data1)
s1 <- sd(data1)

x1_bar # [1] 22.5
s1 # [1] 4.704608

x2_bar <- mean(data2)
s2 <- sd(data2)

x2_bar # [1] 12.9875
s2 # [1] 2.530843

# (b)
n1 <- length(data1)

chi_value1 <- qchisq(p = 0.05 / 2, df = n1 - 1, lower.tail = FALSE)
chi_value2 <- qchisq(p = 1 - 0.05 / 2, df = n1 - 1, lower.tail = FALSE)

(n1 - 1) * s1^2 / chi_value1 # [1] 12.07783
(n1 - 1) * s1^2 / chi_value2 # [1] 53.01704

# library(EnvStats)
# varTest(data1)

# (c)
n2 <- length(data2)

(n2 - 1) * s2^2 / chi_value1 # [1] 3.495203
(n2 - 1) * s2^2 / chi_value2 # [1] 15.3426

# library(EnvStats)
# varTest(data2)

sqrt((n2 - 1) * s2^2 / chi_value1) # [1] 1.869546
sqrt((n2 - 1) * s2^2 / chi_value2) # [1] 3.916964

# (d)
sigma <- 4

chi_statistic <- ((n2 - 1) * s2^2) / sigma^2
critical_value1 <- qchisq(p = 1 - 0.05 / 2, df = n2 - 1, lower.tail = FALSE)
critical_value2 <- qchisq(p = 0.05 / 2, df = n2 - 1, lower.tail = FALSE)

chi_statistic # [1] 6.004844
critical_value1 # [1] 6.262138
critical_value2 # [1] 27.48839

# library(EnvStats)
# varTest(data2, sigma.squared = sigma^2)


# 10-6.2
f_value <- qf(p = 0.05, df1 = 3 - 1, df2 = 8 - 1, lower.tail = FALSE)

f_value # [1] 4.737414


# 10-6.8
p_value <- pf(q = 8.36, df1 = 5, df2 = 4, lower.tail = FALSE)

p_value # [1] 0.03050465


# 10-6.14
s1 <- 15.6
n1 <- 30

s2 <- 28.2
n2 <- 30

f_statistic <- s1^2 / s2^2
p_value <- 1 - pf(q = f_statistic, df1 = n1 - 1, df2 = n2 - 1, lower.tail = FALSE)

p_value # [1] 0.001049035


# 10-6.22
# (a)
s1_squared <- 1.54
n1 <- 15

s2_squared <- 2.96
n2 <- 15

f_statistic <- s1_squared / s2_squared
p_value <- 2 * (1 - pf(q = f_statistic, df1 = n1 - 1, df2 = n2 - 1, lower.tail = FALSE))

p_value # [1] 0.233828

# (b)
f_value1 <- qf(p = 0.01 / 2, df1 = n1 - 1, df2 = n2 - 1, lower.tail = FALSE)
f_value2 <- qf(p = 0.01 / 2, df1 = n2 - 1, df2 = n1 - 1, lower.tail = FALSE)

(s1_squared / s2_squared) * (1 / f_value1) # [1] 0.1210132
(s1_squared / s2_squared) * f_value2 # [1] 2.236791


# Review.2
data <- c(82.10, 75.75, 75.44)

x_bar <- mean(data)
s <- sd(data)
n <- length(data)

t_value <- qt(p = 0.01 / 2, df = n - 1, lower.tail = FALSE)

x_bar - t_value * s / sqrt(n) # [1] 56.22465
x_bar + t_value * s / sqrt(n) # [1] 99.30202

# t.test(x = data, conf.level = 0.99)$conf.int


# Review.8
# (b)
x1_bar <- 128.00
s1 <- 43.00
n1 <- 16

x2_bar <- 78.70
s2 <- 41.7
n2 <- 15

d <- 0
pooled_variance <- ((n1 - 1) * s1^2 + (n2 - 1) * s2^2) / (n1 + n2 - 2)

critical_value1 <- qt(p = 1 - 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)
critical_value2 <- qt(p = 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)
t_statistic <- (x1_bar - x2_bar - d) / sqrt(pooled_variance * (1 / n1 + 1 / n2))

critical_value1 # [1] -2.04523
critical_value2 # [1] 2.04523
t_statistic # [1] 3.236961

# (c)
x1_bar <- 46.80
s1 <- 2.21
n1 <- 16

x2_bar <- 8.10
s2 <- 1.26
n2 <- 15

d <- 0
pooled_variance <- ((n1 - 1) * s1^2 + (n2 - 1) * s2^2) / (n1 + n2 - 2)

critical_value1 <- qt(p = 1 - 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)
critical_value2 <- qt(p = 0.05 / 2, df = n1 + n2 - 2, lower.tail = FALSE)
t_statistic <- (x1_bar - x2_bar - d) / sqrt(pooled_variance * (1 / n1 + 1 / n2))

critical_value1 # [1] -2.04523
critical_value2 # [1] 2.04523
t_statistic # [1] 59.34178


# Review.16
data1 <- c(7, 2, 12, 12)
data2 <- c(13, 3, 18, 13)

d <- data1 - data2

d_bar <- mean(d)
s <- sd(d)
n <- length(d)

t_statistic <- (d_bar - 0) / (s / sqrt(n))
critical_value <- qt(p = 1 - 0.05, df = n - 1, lower.tail = FALSE)

t_statistic # [1] -2.424871
critical_value # [1] -2.353363

# t.test(x = data1, y = data2, paired = TRUE, alternative = "less")
