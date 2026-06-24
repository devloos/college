import 'package:flutter_dotenv/flutter_dotenv.dart';
import 'package:http/http.dart' as http;
import 'dart:convert';

class Weather {
  final String city;
  final double temperature;
  final String description;
  final String main;

  Weather({
    required this.city,
    required this.temperature,
    required this.description,
    required this.main,
  });
}

class WeatherService {
  Future<Weather> fetchWeather(String city) async {
    final apiKey = dotenv.env['OPEN_WEATHER_API_KEY'];

    final response = await http.get(
      Uri.parse(
        'https://api.openweathermap.org/data/2.5/weather?q=$city&appid=$apiKey&units=metric',
      ),
    );

    if (response.statusCode == 200) {
      final data = jsonDecode(response.body);

      return Weather(
        city: data['name'],
        temperature: data['main']['temp'],
        description: data['weather'][0]['description'],
        main: data['weather'][0]['main'],
      );
    } else {
      throw Exception('Failed to load weather data');
    }
  }
}
