# to run the script is required to install "tm" and "wordcloud" libraries to generate cloud
# .cvs format is required as input put all words in one row

# import tm and wordcloud
library("tm")
library("wordcloud")

# reading csv file
data <- read.csv('sentences_inferentials_200.csv', header = F)

# transforming to Corpus object
data_cloud <- Corpus(VectorSource(data))

# removing ponctuations
data_cloud <- tm_map(data_cloud, removePunctuation)

# converting to lowercase
data_cloud <- tm_map(data_cloud, PlainTextDocument)   

#data_cloud <- tm_map(data_cloud, content_transformer(tolower))

# convert to dataframe
data_cloud_converted <-data.frame(text=unlist(sapply(data_cloud, `[`, "content")), stringsAsFactors=F)

# generate word cloud graph
wordcloud(data_cloud, max.words = 500, random.order = FALSE)

# verify all words if needed
inspect(data_cloud)

# sumary all words if needed
summary(data, maxsum = 1700)



