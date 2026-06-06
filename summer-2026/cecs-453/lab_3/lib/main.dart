import 'package:flutter/material.dart';

// CECS 453
// Lab assignment 3
// Just Me: Carlos Aguilera
// Video link: https://www.loom.com/share/46b4087044344d5fa64cf4c7112c9c0f

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Lab 3',
      home: const MyHomePage(title: 'Lab 3'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
  final List<Map<String, String>> affirmations = [
    {
      'image': 'assets/images/1.jpg',
      'affirmation': 'I am worthy of love and abundance.',
    },
    {
      'image': 'assets/images/2.jpg',
      'affirmation': 'I am deserving of success and prosperity.',
    },
    {
      'image': 'assets/images/3.jpg',
      'affirmation': 'I am open to receiving love and abundance.',
    },
    {
      'image': 'assets/images/4.jpg',
      'affirmation': 'I am deserving of success and prosperity.',
    },
    {
      'image': 'assets/images/5.jpg',
      'affirmation': 'I am open to receiving love and abundance.',
    },
  ];

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(),
      body: Center(
        child: ListView.separated(
          padding: const EdgeInsets.all(8),
          physics: const BouncingScrollPhysics(),
          itemCount: 5,
          separatorBuilder: (context, index) => const SizedBox(height: 20),
          itemBuilder: (context, index) {
            return Container(
              clipBehavior: Clip.hardEdge,
              decoration: BoxDecoration(
                borderRadius: BorderRadius.circular(16),
                color: Colors.purple[100],
              ),
              child: Column(
                children: [
                  Image.asset(
                    affirmations[index]['image']!,
                    width: double.infinity,
                    height: 300,
                    fit: BoxFit.cover,
                    alignment: Alignment.bottomCenter,
                  ),
                  const SizedBox(height: 20),
                  Text(
                    affirmations[index]['affirmation']!,
                    style: const TextStyle(
                      fontSize: 20,
                      fontWeight: FontWeight.bold,
                    ),
                  ),
                  const SizedBox(height: 20),
                ],
              ),
            );
          },
        ),
      ),
    );
  }
}
