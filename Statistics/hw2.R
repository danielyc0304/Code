# 11-2.4
data <- data.frame(
  x = c(13, 17, 15, 16, 18, 18, 15, 18, 17, 24, 23, 20),
  technique = rep(c(1, 2, 3), each = 4)
)

n <- nrow(data)
k <- length(unique(data$technique))

technique1 <- data[data$technique == 1, "x"]
technique2 <- data[data$technique == 2, "x"]
technique3 <- data[data$technique == 3, "x"]

ss <- function(vec) {
  sum((vec - mean(vec))^2)
}

ss_total <- ss(data$x)
ss_treat <- ss(rep(c(mean(technique1), mean(technique2), mean(technique3)), each = 4))
ss_error <- ss(technique1) + ss(technique2) + ss(technique3)

mst <- ss_treat / (k - 1)
mse <- ss_error / (n - k)

f_statistic <- mst / mse
p_value <- 2 * pf(q = f_statistic, df1 = k - 1, df2 = n - k, lower.tail = FALSE)
p_value # [1] 0.03248869

# summary(aov(x ~ factor(technique), data = data))


# 11-2.8(a)
data <- data.frame(
  x = c(73, 83, 76, 68, 80, 54, 74, 71, 79, 95, 87),
  method = rep(c("A", "B", "C"), times = c(5, 3, 3))
)

n <- nrow(data)
num_treat <- length(unique(data$method))

method_a <- data[data$method == "A", "x"]
method_b <- data[data$method == "B", "x"]
method_c <- data[data$method == "C", "x"]

ss <- function(vec) {
  sum((vec - mean(vec))^2)
}

ss_total <- ss(data$x)
ss_treat <- ss(rep(c(mean(method_a), mean(method_b), mean(method_c)), times = c(5, 3, 3)))
ss_error <- ss(method_a) + ss(method_b) + ss(method_c)

mst <- ss_treat / (k - 1)
mse <- ss_error / (n - k)

critical_value1 <- qf(p = 1 - 0.05, df1 = k - 1, df2 = n - k, lower.tail = FALSE)
critical_value2 <- qf(p = 0.05, df1 = k - 1, df2 = n - k, lower.tail = FALSE)
f_statistic <- mst / mse

critical_value1 # [1] 0.05162358
critical_value2 # [1] 4.45897
f_statistic # [1] 5.14876

# summary(aov(x ~ factor(method), data = data))


# 11-2.14
# (a)
data <- data.frame(
  x = c(
    0.99, 1.92, 1.23, 0.85, 0.65, 0.69, 0.60, 0.53, 1.41, 1.12, 0.63, 0.67, 0.60, 0.66,
    1.49, 1.29, 1.27, 1.35, 1.29, 1.00, 1.27, 1.28,
    1.27, 1.22, 1.19, 1.22,
    2.56, 1.92, 1.30, 1.79, 1.23, 0.62, 0.66, 0.62, 0.65, 0.60, 0.67
  ),
  brand = rep(c("light_water", "white_water", "white_oil", "light_oil"), times = c(14, 8, 4, 11))
)

summary(aov(x ~ factor(brand), data = data))

# (c)
n <- nrow(data)
k <- length(unique(data$brand))

light_water <- data[data$brand == "light_water", "x"]
light_oil <- data[data$brand == "light_oil", "x"]

x1_bar <- mean(light_water)
x2_bar <- mean(light_oil)

t_value <- qt(p = 0.05 / 2, df = n - k, lower.tail = FALSE)
mse <- 0.2064

(x1_bar - x2_bar) - t_value * sqrt(mse * (1 / length(light_water) + 1 / length(light_oil))) # [1] -0.6232577
(x1_bar - x2_bar) + t_value * sqrt(mse * (1 / length(light_water) + 1 / length(light_oil))) # [1] 0.1215694

# library("DescTools")
# PostHocTest(aov(x ~ factor(brand), data = data), method = "lsd")

# (d)
white_water <- data[data$brand == "white_water", "x"]
white_oil <- data[data$brand == "white_oil", "x"]

x1_bar <- mean(white_water)
x2_bar <- mean(white_oil)

(x1_bar - x2_bar) - t_value * sqrt(mse * (1 / length(white_water) + 1 / length(white_oil))) # [1] -0.5110196
(x1_bar - x2_bar) + t_value * sqrt(mse * (1 / length(white_water) + 1 / length(white_oil))) # [1] 0.6210196

# library("DescTools")
# PostHocTest(aov(x ~ factor(brand), data = data), method = "lsd")


# 11-3.2
qtukey(p = 0.05, nmeans = 5, df = 10, lower.tail = FALSE) # [1] 4.654293


# 11-3.8
q_value <- qtukey(p = 0.05, nmeans = 4, df = 16, lower.tail = FALSE)
s <- sqrt(8)
nt <- 5

q_value * (s / sqrt(nt)) # [1] 5.117948


# 11-3.18
# (a)
data <- data.frame(
  x = c(
    29, 33, 26, 27, 39, 35, 33, 29, 36, 22,
    24, 27, 33, 31, 21, 28, 24, 34, 21, 32,
    37, 25, 22, 33, 28, 26, 30, 34, 27, 33,
    28, 29, 34, 36, 21, 20, 25, 24, 33, 32
  ),
  group = rep(c(1, 2, 3, 4), each = 10)
)

n <- nrow(data)
k <- length(unique(data$group))

data1 <- data[data$group == 1, "x"]
data2 <- data[data$group == 2, "x"]
data3 <- data[data$group == 3, "x"]
data4 <- data[data$group == 4, "x"]

x1_bar <- mean(data1) # [1] 30.9
x2_bar <- mean(data2) # [1] 27.5
x3_bar <- mean(data3) # [1] 29.5
x4_bar <- mean(data4) # [1] 28.2

q_value <- qtukey(p = 0.05, nmeans = k, df = n - k, lower.tail = FALSE)

ss <- function(vec) {
  sum((vec - mean(vec))^2)
}
ss_error <- ss(data1) + ss(data2) + ss(data3) + ss(data4)
mse <- ss_error / (n - k)

nt <- length(data1)

x1_bar - x2_bar # [1] 3.4
q_value * sqrt(mse / nt) # [1] 6.139862

# (b)
library("DescTools")
PostHocTest(aov(x ~ factor(group), data = data), method = "hsd")


# 11-4.20
# (a)
data <- data.frame(
  x = c(
    1342, 1608, 1881,
    1698, 1387, 1140,
    1296, 1029, 1549,
    1150, 1579, 1319
  ),
  digitalis = c(
    "A", "B", "C",
    "C", "B", "A",
    "B", "A", "C",
    "A", "C", "B"
  ),
  dog = rep(c(1, 2, 3, 4), each = 3)
)

n <- nrow(data)
k <- length(unique(data$digitalis))
b <- length(unique(data$dog))

df_error <- (k - 1) * (b - 1) # [1] 6

# (b)
g <- sum(data$x)
cm <- g^2 / n

ss_total <- sum(data$x^2) - cm

digitalis_a <- data[data$digitalis == "A", "x"]
digitalis_b <- data[data$digitalis == "B", "x"]
digitalis_c <- data[data$digitalis == "C", "x"]
ss_treat <- (sum(digitalis_a)^2 + sum(digitalis_b)^2 + sum(digitalis_c)^2) / b - cm

dog1 <- data[data$dog == 1, "x"]
dog2 <- data[data$dog == 2, "x"]
dog3 <- data[data$dog == 3, "x"]
dog4 <- data[data$dog == 4, "x"]
ss_block <- (sum(dog1)^2 + sum(dog2)^2 + sum(dog3)^2 + sum(dog4)^2) / k - cm

ss_error <- ss_total - ss_treat - ss_block

mst <- ss_treat / (k - 1)
mse <- ss_error / df_error

critical_value1 <- qf(p = 1 - 0.05, df1 = k - 1, df2 = df_error, lower.tail = FALSE)
critical_value2 <- qf(p = 0.05, df1 = k - 1, df2 = df_error, lower.tail = FALSE)
f_statistic <- mst / mse

critical_value1 # [1] 0.0517343
critical_value2 # [1] 5.143253
f_statistic # [1] 258.2366

# summary(aov(x ~ factor(digitalis) + factor(dog), data = data))

# (c)
library("DescTools")
PostHocTest(aov(x ~ factor(digitalis) + factor(dog), data = data), method = "hsd", conf.level = 0.99)

# (d)
msb <- ss_block / (b - 1)

critical_value1 <- qf(p = 1 - 0.05, df1 = b - 1, df2 = df_error, lower.tail = FALSE)
critical_value2 <- qf(p = 0.05, df1 = b - 1, df2 = df_error, lower.tail = FALSE)
f_statistic <- msb / mse

critical_value1 # [1] 0.1118488
critical_value2 # [1] 4.757063
f_statistic # [1] 56.95542

# summary(aov(x ~ factor(digitalis) + factor(dog), data = data))

# (e)
library("DescTools")
PostHocTest(aov(x ~ factor(digitalis) + factor(dog), data = data), method = "hsd", conf.level = 0.99)

# (f)
sqrt(mse / b) # [1] 15.92888

# (g)
t1_bar <- mean(digitalis_a)
t2_bar <- mean(digitalis_b)

t_value <- qt(p = 0.05 / 2, df = df_error, lower.tail = FALSE)

(t1_bar - t2_bar) - t_value * sqrt(2 * mse / b) # [1] -292.3712
(t1_bar - t2_bar) + t_value * sqrt(2 * mse / b) # [1] -182.1288

# library("DescTools")
# PostHocTest(aov(x ~ factor(digitalis) + factor(dog), data = data), method = "lsd")


# 11-4.22
# (b)
data <- data.frame(
  x = c(
    3447, 3572, 3393, 3492,
    3156, 3108, 3110, 3300,
    3844, 3507, 3449, 3646,
    3063, 2767, 2727, 2931,
    3914, 3460, 3686, 3568
  ),
  company = rep(c("All-state", "21st Century", "Nationwide", "AAA", "State Farm"), each = 4),
  city = rep(c("Long Beach", "Pomona", "San Bernardino", "Moreno Valley"), times = 5)
)

n <- nrow(data)
k <- length(unique(data$company))
b <- length(unique(data$city))

g <- sum(data$x)
cm <- g^2 / n

ss_total <- sum(data$x^2) - cm

company_1 <- data[data$company == "All-state", "x"]
company_2 <- data[data$company == "21st Century", "x"]
company_3 <- data[data$company == "Nationwide", "x"]
company_4 <- data[data$company == "AAA", "x"]
company_5 <- data[data$company == "State Farm", "x"]
ss_treat <- (sum(company_1)^2 + sum(company_2)^2 + sum(company_3)^2 + sum(company_4)^2 + sum(company_5)^2) / b - cm

city_1 <- data[data$city == "Long Beach", "x"]
city_2 <- data[data$city == "Pomona", "x"]
city_3 <- data[data$city == "San Bernardino", "x"]
city_4 <- data[data$city == "Moreno Valley", "x"]
ss_block <- (sum(city_1)^2 + sum(city_2)^2 + sum(city_3)^2 + sum(city_4)^2) / k - cm

ss_error <- ss_total - ss_treat - ss_block

mst <- ss_treat / (k - 1)
mse <- ss_error / ((k - 1) * (b - 1))

critical_value1 <- qf(p = 1 - 0.05, df1 = k - 1, df2 = (k - 1) * (b - 1), lower.tail = FALSE)
critical_value2 <- qf(p = 0.05, df1 = k - 1, df2 = (k - 1) * (b - 1), lower.tail = FALSE)
f_statistic <- mst / mse

critical_value1 # [1] 0.1691552
critical_value2 # [1] 3.259167
f_statistic # [1] 30.88336

# summary(aov(x ~ factor(company) + factor(city), data = data))

# (c)
msb <- ss_block / (b - 1)

critical_value1 <- qf(p = 1 - 0.05, df1 = b - 1, df2 = (k - 1) * (b - 1), lower.tail = FALSE)
critical_value2 <- qf(p = 0.05, df1 = b - 1, df2 = (k - 1) * (b - 1), lower.tail = FALSE)
f_statistic <- msb / mse

critical_value1 # [1] 0.1143558
critical_value2 # [1] 3.490295
f_statistic # [1] 3.490728

summary(aov(x ~ factor(company) + factor(city), data = data))

# (d)
library("DescTools")
PostHocTest(aov(x ~ factor(company) + factor(city), data = data), method = "hsd")


# 12-1.20
data <- data.frame(
  x = 1:6,
  y = c(5.6, 4.6, 4.5, 3.7, 3.2, 2.7)
)

n <- nrow(data)

sxy <- sum(data$x * data$y) - sum(data$x) * sum(data$y) / n
sxx <- sum(data$x^2) - sum(data$x)^2 / n

b <- sxy / sxx
a <- mean(data$y) - b * mean(data$x)

a # [1] 6
b # [1] -0.5571429

# summary(lm(y ~ x, data = data))


# 12-1.22
# (a)
data <- data.frame(
  armspan = c(172, 158, 165, 176, 172, 175, 157, 153),
  height = c(175, 157, 165, 177, 170, 170, 160, 157)
)

plot(x = data$armspan, y = data$height, pch = 16, xlab = "Armspan", ylab = "Height")

# (c)
n <- nrow(data)
x <- data$armspan
y <- data$height

sxy <- sum(x * y) - sum(x) * sum(y) / n
sxx <- sum(x^2) - sum(x)^2 / n

b <- sxy / sxx
b # [1] 0.8239437

# summary(lm(y ~ x, data = data))

# (d)
a <- mean(y) - b * mean(x)

a + b * 157 # [1] 158.9595


# 12-2.10
# (b)
data <- data.frame(
  income = c(15, 20.5, 30, 40, 60, 70),
  bmi = c(31.2, 29.3, 27.4, 27.3, 26.8, 20.0)
)

n <- nrow(data)
x <- data$income
y <- data$bmi

sxy <- sum(x * y) - sum(x) * sum(y) / n
sxx <- sum(x^2) - sum(x)^2 / n

b <- sxy / sxx
a <- mean(y) - b * mean(x)

a # [1] 33.01118
b # [1] -0.1531512

# summary(lm(y ~ x, data = data))

# (c)
summary(aov(y ~ x, data = data))


# 12-2.12
# (a)
data <- data.frame(
  x = c(19.1, 38.2, 57.3, 76.2, 95, 114, 131, 150, 170),
  y = c(0.095, 0.174, 0.256, 0.348, 0.429, 0.500, 0.580, 0.651, 0.722)
)

n <- nrow(data)

sxx <- sum(data$x^2) - sum(data$x)^2 / n
syy <- sum(data$y^2) - sum(data$y)^2 / n
sxy <- sum(data$x * data$y) - sum(data$x) * sum(data$y) / n

sxx # [1] 21066.82
syy # [1] 0.3747976
sxy # [1] 88.80003

# (b)
b <- sxy / sxx
a <- mean(data$y) - b * mean(data$x)

a # [1] 0.01874902
b # [1] 0.004215161

summary(lm(y ~ x, data = data))

# (c)
plot(x = data$x, y = data$y, xlab = "Ni", ylab = "Peak Current", pch = 16)
abline(a = a, b = b)

# (d)
a + b * 100 # [1] 0.4402651

# (e)
summary(aov(y ~ x, data = data))


# 12-3.12
# (b)
data <- data.frame(
  gestation = c(187, 219, 285, 63, 250, 52, 151, 258, 330, 166, 21, 112, 90, 154, 63),
  avg_longevity = c(20, 18, 15, 12, 15, 7, 8, 20, 20, 15, 3, 10, 12, 12, 5)
)

n <- nrow(data)
x <- data$gestation
y <- data$avg_longevity

sxy <- sum(x * y) - sum(x) * sum(y) / n
sxx <- sum(x^2) - sum(x)^2 / n

b <- sxy / sxx
a <- mean(y) - b * mean(x)

a # [1] 5.057938
b # [1] 0.04836773

# summary(lm(y ~ x, data = data))

# (c)
plot(x = x, y = y, xlab = "Gestation", ylab = "Avg Longevity", pch = 16)
abline(a = a, b = b)

# (d)
syy <- sum(y^2) - sum(y)^2 / n

sse <- syy - sxy^2 / sxx
mse <- sse / (n - 2)

critical_value1 <- qt(p = 1 - 0.05 / 2, df = n - 2, lower.tail = FALSE)
critical_value2 <- qt(p = 0.05 / 2, df = n - 2, lower.tail = FALSE)
t_statistic <- (b - 0) / sqrt(mse / sxx)

critical_value1 # [1] -2.160369
critical_value2 # [1] 2.160369
t_statistic # [1] 5.351658

# summary(lm(y ~ x, data = data))
