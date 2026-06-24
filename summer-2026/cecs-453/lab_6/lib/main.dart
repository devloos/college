import 'package:flutter/material.dart';
import 'package:flutter_dotenv/flutter_dotenv.dart';
import 'services/weather_service.dart';

Future<void> main() async {
  WidgetsFlutterBinding.ensureInitialized();

  await dotenv.load(fileName: ".env");

  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Weather App',
      theme: ThemeData(
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.blue),
      ),
      home: const MyHomePage(title: 'Weather App'),
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
  final TextEditingController _cityController = TextEditingController(
    text: 'London',
  );
  bool _isLoading = false;
  Map<String, dynamic> _weather = {};

  @override
  void initState() {
    super.initState();
    _fetchWeather();
  }

  Future<void> _fetchWeather() async {
    if (_cityController.text.isEmpty) {
      return;
    }

    try {
      setState(() {
        _isLoading = true;
      });

      final weatherService = WeatherService();
      final response = await weatherService.fetchWeather(_cityController.text);

      setState(() {
        _weather = response;
      });
    } catch (e) {
      print(e);
    } finally {
      setState(() {
        _isLoading = false;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        backgroundColor: Theme.of(context).colorScheme.inversePrimary,
        title: Text(widget.title),
      ),
      body: Center(
        child: Column(
          children: [
            SizedBox(height: 30),
            Padding(
              padding: const EdgeInsets.all(8.0),
              child: TextField(
                controller: _cityController,
                decoration: InputDecoration(
                  labelText: 'City',
                  border: OutlineInputBorder(),
                ),
              ),
            ),
            ElevatedButton(
              onPressed: _fetchWeather,
              child: Text('Fetch Weather'),
            ),
            SizedBox(height: 30),
            if (_isLoading)
              const CircularProgressIndicator()
            else
              Column(
                children: [
                  Text('Weather in ${_cityController.text}:'),
                  Text(
                    _weather.toString(),
                    style: Theme.of(context).textTheme.headlineMedium,
                  ),
                ],
              ),
          ],
        ),
      ),
    );
  }
}
