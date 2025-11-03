import Data.List (sortBy)
import Data.Ord (comparing, Down(..))

data Person = Person { name :: String, age :: Int }

numbers :: [Double]
numbers = [645.41, 37.59, 76.41, 5.31, -34.23, 1.11, 1.10, 23.46, 
           635.47, -876.32, 467.83, 62.25]

people :: [Person]
people = [
    Person "Hal" 20, Person "Susann" 31, Person "Dwight" 19, Person "Kassandra" 21,
    Person "Lawrence" 25, Person "Cindy" 22, Person "Cory" 27, Person "Mac" 19,
    Person "Romana" 27, Person "Doretha" 32, Person "Danna" 20, Person "Zara" 23,
    Person "Rosalyn" 26, Person "Risa" 24, Person "Benny" 28, Person "Juan" 33,
    Person "Natalie" 25
    ]

-- Sort numbers in ascending order by numerical value
-- Uses the default Ord instance for Double
-- Used google to find this
sortNumbersAscending :: [Double] -> [Double]
sortNumbersAscending = sortBy (comparing id)

-- Sort people alphabetically by name
-- Uses comparing function with name
sortPeopleByName :: [Person] -> [Person]
sortPeopleByName = sortBy (comparing name)

-- Sort people by age (descending), then by name (alphabetical)
-- Uses Down to reverse age order, then comparing by name
sortPeopleByAgeDescThenName :: [Person] -> [Person]
-- this uses monoid comparison, learned this from ChatGPT
sortPeopleByAgeDescThenName = sortBy (comparing (Down . age) <> comparing name)

printPerson :: Person -> IO ()
printPerson p = putStrLn (name p ++ ", " ++ show (age p))

main :: IO ()
main = do
    putStrLn "CECS 342 Assignment 1"
    putStrLn "Name: Carlos Aguilera"
    putStrLn "Algorithm: quick sort, Language: Haskell\n"
    
    -- Sort numbers in ascending order
    let sortedNumbers = sortNumbersAscending numbers
    putStrLn "Numbers sorted in ascending order:"
    -- underscore means ignore the result, (this is primarily for my IDE)
    mapM_ print sortedNumbers
    putStrLn ""
    
    -- Sort people alphabetically by name
    let sortedByName = sortPeopleByName people
    putStrLn "People sorted alphabetically by name:"
    mapM_ printPerson sortedByName

    putStrLn ""

    -- Sort people by age (descending), then by name
    let sortedByAgeDesc = sortPeopleByAgeDescThenName people
    putStrLn "People sorted by age (descending), then by name:"
    mapM_ printPerson sortedByAgeDesc



