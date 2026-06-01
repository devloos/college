import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(),
    );
  }
}

class MyHomePage extends StatelessWidget {
  const MyHomePage({super.key});

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text('Flutter Demo Home Page')),
      body: Column(
        mainAxisAlignment: MainAxisAlignment.center,
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          SizedBox(height: 200.0),
          Expanded(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Container(
                  width: 120.0,
                  height: 100.0,
                  child: Placeholder(
                    fallbackWidth: 120.0,
                    fallbackHeight: 100.0,
                  ),
                ),
                Text(
                  'Full Name',
                  style: TextStyle(fontSize: 30.0, fontWeight: FontWeight.bold),
                ),
                Text(
                  'Title',
                  style: TextStyle(fontSize: 24.0, fontWeight: FontWeight.bold),
                ),
              ],
            ),
          ),
          Expanded(
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              children: [
                Row(
                  children: [
                    Placeholder(fallbackWidth: 40.0, fallbackHeight: 40.0),
                    SizedBox(width: 10.0),
                    Text('+61 412 345 678'),
                  ],
                ),
                SizedBox(height: 10.0),
                Row(
                  children: [
                    Placeholder(fallbackWidth: 40.0, fallbackHeight: 40.0),
                    SizedBox(width: 10.0),
                    Text('@social_media'),
                  ],
                ),
                SizedBox(height: 10.0),
                Row(
                  children: [
                    Placeholder(fallbackWidth: 40.0, fallbackHeight: 40.0),
                    SizedBox(width: 10.0),
                    Text('email@example.com'),
                  ],
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}
