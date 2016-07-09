
name := "LeetCodeScala"
version := "0.0.1"
scalaVersion := "2.11.8"
sbtVersion := "0.13.11"


resolvers += "Typesafe Repository" at "http://repo.typesafe.com/typesafe/releases/"

resolvers += "repo.novus rels" at "http://repo.novus.com/releases/"

resolvers += "Sonatype releases" at "https://oss.sonatype.org/content/repositories/releases"

resolvers += "rediscala" at "http://dl.bintray.com/etaty/maven"

resolvers += "RoundEights" at "http://maven.spikemark.net/roundeights"

scalacOptions ++= Seq(
	"-deprecation", 
	"-unchecked", 
	"-feature", 
	"-Xlint",
	"-Ywarn-dead-code", 
	"-Ywarn-value-discard"
	)

libraryDependencies ++= Seq(
  "org.scalatest"     % "scalatest_2.11" % "2.2.1" % "test"
  )

libraryDependencies += "joda-time" % "joda-time" % "2.9.4" withSources()
